#pragma once
#include<Windows.h>
#include "ConsoleGraphics.h"


class DartBoard : private ConsoleGraphics
{
	public:
		// Constructor
		DartBoard();

		// Destructor
		~DartBoard();

		// Draws a Dart Board on the console with specified centre point.
		void DrawDartBoard();

		// Prints Window Width and Height
		void PrintWindowDims();

	private:
		int boardRadius;
		const COLORREF YELLOW = RGB(245, 239, 66);
		const COLORREF RED = RGB(255, 0, 0);
		const COLORREF GREEN = RGB(0, 255, 0);

		// Gets the console window size;
		RECT GetScreenInfo();

		// Sets board radius based on screen resolution
		int setBoardSize(RECT screenInfo);

		// Return Ring Radius
		double ringRadius(double boardRadius, double offset);

		// Return Target Radius
		double targetRadius(double outerRing, double innerRing);
};

