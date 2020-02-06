#pragma once
#include<windows.h>
#include<iostream>
#include <cmath>

using namespace std;

class ConsoleGraphics {

	public:
	// Constructor
	ConsoleGraphics();

	// Destructor
	~ConsoleGraphics();

	// Lines
	// -----
	void DrawLine(COORD, COORD);
	void DrawAngleLine(COORD, int, int);
	void DrawAngleLine(COORD, int, int, COLORREF);
	void DrawAngleLine(COORD, COORD, int);


	// Circles
	// -------
	void DrawCircle(COORD, int);
	void DrawCircle(COORD, int, COLORREF);
	void SegmentCircle(COORD, int, int);
	COORD CicleCoordinate(COORD, int, double);


	private:

	#define PI 3.14
	HWND myConsole;
	HDC myDC;
};

