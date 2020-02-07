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
	void DrawAngleLine(COORD startPoint, int angleDeg, int length);
	void DrawAngleLine(COORD startPoint, int angleDeg, int length, COLORREF color);
	void DrawAngleLine(COORD startPoint, int angleDeg, int length, int startCutLength);


	// Circles
	// -------
	void DrawCircle(COORD centre, int radius);
	void DrawCircle(COORD centre, int radius, COLORREF lineColor);
	void SegmentCircle(COORD centre, int radius, int segments);
	void SegmentCircle(COORD centre, int radius, int segments, int startCutLength);
	void SegmentCircle(COORD centre, int radius, int segments, int startCutLength, int offsetDeg);
	COORD CicleCoordinate(COORD centre, int radius, double angleDeg);


	private:

	#define PI 3.14
	HWND myConsole;
	HDC myDC;
};

