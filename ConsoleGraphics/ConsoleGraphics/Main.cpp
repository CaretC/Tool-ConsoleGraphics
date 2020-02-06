/*
A class for drawing simple graphics in the console window.
*/

// Includes
// --------
#include<iostream>
#include "ConsoleGraphics.h"

using namespace std;

// Main
// ----
int main() {

	ConsoleGraphics cg;

	COORD cent1;
	cent1.X = 150;
	cent1.Y = 150;

	cg.DrawCircle(cent1, 100);
	cg.DrawAngleLine(cent1, 0, 100);

	COORD cent2;
	cent2.X = 360;
	cent2.Y = 150;

	cg.SegmentCircle(cent2, 100, 10);

	for (int i = 0; i < 360; i += 90) {
		cg.DrawAngleLine(cent2, i, 100, COLORREF(RGB(255, 0,0)));
	}

	COORD cent3;
	cent3.X = 700;
	cent3.Y = 150;

	for (double i = 0; i < 360; i += 10.0) {
		cg.DrawCircle(cg.CicleCoordinate(cent3, 100, i), 5);
	}

	COORD cent4;
	cent4.X = 470;
	cent4.Y = 350;

	cg.DrawCircle(cent4, 100);

	for (int i = 0; i < 360; i += 5) {
		cg.DrawAngleLine(cent4, i, 100);
	}

	for (int i = 0; i < 360; i ++) {
		cg.DrawAngleLine(cent4, i, 100, COLORREF(RGB(0,255,0)));
	}
	
	

	cin.ignore(); // Hold system until key is pressed
	return 0;
}