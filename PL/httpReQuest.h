#pragma once
#include <windows.h>
#include <tchar.h>
#include <wininet.h>
#include <string>
#include <atlstr.h>
#pragma comment(lib, "wininet.lib")
#include "VMProtectUltra.h"
#pragma comment(lib, "VMProtectSDK64.lib")

using namespace std;


char* Post_Query(const char* szURL, const   char* szPostData)

{
	
	VMProtectBeginUltra("HttpRequestSession");
	CString aString;

	aString = "";



	HINTERNET hSession = ::InternetOpen("TestOpen", 0, NULL, NULL, NULL);
	if (hSession)

	{

		// crack url..

		char szExtraInfo[MAX_PATH];

		char szHostName[MAX_PATH];

		char szPassword[MAX_PATH];

		char szScheme[MAX_PATH];

		char szUrlPath[MAX_PATH * 4];

		char szUserName[MAX_PATH];



		URL_COMPONENTS      urlcomponent;

		urlcomponent.dwExtraInfoLength = MAX_PATH;

		urlcomponent.dwHostNameLength = MAX_PATH;

		urlcomponent.dwPasswordLength = MAX_PATH;

		urlcomponent.dwSchemeLength = MAX_PATH;

		urlcomponent.dwStructSize = sizeof(URL_COMPONENTS);

		urlcomponent.dwUrlPathLength = MAX_PATH * 4;

		urlcomponent.dwUserNameLength = MAX_PATH;

		urlcomponent.lpszExtraInfo = szExtraInfo;

		urlcomponent.lpszHostName = szHostName;

		urlcomponent.lpszPassword = szPassword;

		urlcomponent.lpszScheme = szScheme;

		urlcomponent.lpszUrlPath = szUrlPath;

		urlcomponent.lpszUserName = szUserName;

		urlcomponent.nPort = 0;

		//urlcomponent.nScheme = 0;

		::InternetCrackUrl(szURL, sizeof(URL_COMPONENTS), NULL, &urlcomponent);

		// download user

		HINTERNET hConnect = ::InternetConnect(hSession,

			urlcomponent.lpszHostName,

			urlcomponent.nPort,

			urlcomponent.lpszUserName,

			urlcomponent.lpszPassword,

			urlcomponent.nScheme,

			NULL,

			NULL);

		if (hConnect)

		{

			// connected server..

			HINTERNET hObject = ::HttpOpenRequest(hConnect,

				szPostData == NULL ? "GET" : "POST",

				urlcomponent.lpszUrlPath,

				"HTTP/1.1",

				"text/*",

				NULL,

				INTERNET_FLAG_RELOAD,

				NULL);

			if (hObject)

			{

				// post header

				char szLen[MAX_PATH];

				CString aHeader;

				aHeader = "";



				wsprintf(szLen, "%d", szPostData == NULL ? 0 : strlen(szPostData));

				aHeader += _T("Accept: text/*\r\n");

				aHeader += _T("User-Agent: Mozilla/4.0 (compatible; MSIE 5.0;* Windows NT)\r\n");

				aHeader += _T("Content-type: application/x-www-form-urlencoded\r\n");

				aHeader += _T("Content-length: ");

				aHeader += szLen;

				aHeader += _T("\r\n\n");



				::HttpAddRequestHeaders(hObject, (LPCTSTR)aHeader, -1L, HTTP_ADDREQ_FLAG_ADD);



				// post data..

				if (szPostData)

				{

					::HttpSendRequest(hObject, NULL, 0L, (LPVOID)szPostData, strlen(szPostData));

				}

				else

				{

					::HttpSendRequest(hObject, NULL, 0L, NULL, 0);

				}



				// open object

				char szBuffer[1024];

				DWORD dwRead = 0;

				//DWORD dwWrite = 0;



				while (::InternetReadFile(hObject, szBuffer, 1023, &dwRead) &&

					dwRead > 0)

				{

					szBuffer[dwRead] = 0;

					aString += szBuffer;

					Sleep(1);

				}

				::InternetCloseHandle(hObject);

				//bDownLoad = TRUE;

			}

		}

	}

	if (aString && aString.GetLength() > 0)

	{

		char* pReturn = new char[aString.GetLength() + 1];

		strcpy(pReturn, aString);

		return pReturn;

	}
	VMProtectEnd();
	return 0;

}
