#pragma once
#include <Windows.h>
#include <iostream>
#include "GetModule.h"
using namespace std;

class Context
{
public:
	float FOV = 0.054f, TriggerFov = 0.006f, Height = 1.0f, Humanize = 0.2f, PredictionAim = 24.0f;
	BYTE PredictionSwitch = 0, Trigger_Switch = 0, Glow_Switch = 0, Y_Axis_Switch = 0;

	void SetValue(string Pos, string Fov, string Fov2, string Humaniz, string PreSwit, string PreAim, string GlowSwit, string YAxis)
	{


		FOV = ::atof(Fov.c_str());
		TriggerFov = ::atof(Fov2.c_str());
	
		Humanize = ::atof(Humaniz.c_str());
		PredictionAim = ::atof(PreAim.c_str());
		Height = ::atof(Pos.c_str());
		if (PreSwit == "Prediction" || PreSwit == "prediction" || PreSwit == "PREDICTION") PredictionSwitch = 1;
		else PredictionSwitch = 0;
		if (GlowSwit == "EDGE" || GlowSwit == "Edge" || GlowSwit == "edge") Glow_Switch = 1;
		else Glow_Switch = 0;
		if (YAxis == "Axis" || YAxis == "axis" || YAxis == "AXIS") Y_Axis_Switch = 1;
		else Y_Axis_Switch = 0;
	}
};

extern Context* PRESET = new Context();