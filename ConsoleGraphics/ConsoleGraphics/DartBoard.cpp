#include "DartBoard.h"

// Public
// ======
DartBoard::DartBoard()
{
	RECT screenInfo = DartBoard::GetScreenInfo();
	DartBoard::boardRadius = DartBoard::setBoardSize(screenInfo);
}

DartBoard::~DartBoard()
{
}

void DartBoard::DrawDartBoard()
{
	double bRadius = DartBoard::boardRadius;
	double boardXOffset = 10;
	double boardYOffest = 10;
	double doubleBottomRingOffset = 0.08;
	double trebleTopRingOffset = 0.4;
	double trebleBottomRingOffset = 0.48;
	double outerBullTopRingOffset = 0.85;
	double outerBullBottomRingOffset = 0.93;

	COORD centre;
	centre.X = bRadius + (bRadius / boardXOffset);
	centre.Y = bRadius + (bRadius / boardYOffest);

	

	// Draw Outer Edge
	ConsoleGraphics::DrawCircle(centre, bRadius);

	// Draw Double Space Bottom Edge
	ConsoleGraphics::DrawCircle(centre, DartBoard::ringRadius(bRadius, doubleBottomRingOffset));

	// Draw Treble Space Top Edge
	ConsoleGraphics::DrawCircle(centre, DartBoard::ringRadius(bRadius, trebleTopRingOffset));

	// Draw Treble Space Bottom Edge
	ConsoleGraphics::DrawCircle(centre, DartBoard::ringRadius(bRadius, trebleBottomRingOffset));

	// Draw Outer Bull Space Top Edge
	ConsoleGraphics::DrawCircle(centre, DartBoard::ringRadius(bRadius, outerBullTopRingOffset));

	// Draw Outer Bull Space Bottom Edge
	ConsoleGraphics::DrawCircle(centre, DartBoard::ringRadius(bRadius, outerBullBottomRingOffset));

	// Draw Segments
	ConsoleGraphics::SegmentCircle(centre, bRadius, 20, DartBoard::ringRadius(bRadius, outerBullTopRingOffset), 9);

	// Draw Targets Doubles
	for (int i = 0; i < 360; i += 18) {
		ConsoleGraphics::DrawCircle(ConsoleGraphics::CicleCoordinate(centre,
			DartBoard::targetRadius(bRadius, DartBoard::ringRadius(bRadius, doubleBottomRingOffset)), i), 2, DartBoard::YELLOW);
	}

	// Draw Targets Singles Top
	for (int i = 0; i < 360; i += 18) {
		ConsoleGraphics::DrawCircle(ConsoleGraphics::CicleCoordinate(centre,
			DartBoard::targetRadius(DartBoard::ringRadius(bRadius, doubleBottomRingOffset),
				DartBoard::ringRadius(bRadius, trebleTopRingOffset)), i), 2, DartBoard::YELLOW);
	}

	// Draw Targets Trebles
	for (int i = 0; i < 360; i += 18) {
		ConsoleGraphics::DrawCircle(ConsoleGraphics::CicleCoordinate(centre,
			DartBoard::targetRadius(DartBoard::ringRadius(bRadius, trebleTopRingOffset),
				DartBoard::ringRadius(bRadius, trebleBottomRingOffset)), i), 2, DartBoard::YELLOW);
	}

	// Draw Targets Singles Bottom
	for (int i = 0; i < 360; i += 18) {
		ConsoleGraphics::DrawCircle(ConsoleGraphics::CicleCoordinate(centre,
			DartBoard::targetRadius(DartBoard::ringRadius(bRadius, trebleBottomRingOffset),
				DartBoard::ringRadius(bRadius, outerBullTopRingOffset)), i), 2, DartBoard::YELLOW);
	}

	// Draw Targets Outer Bull's Eye
	for (int i = 0; i < 360; i += 90) {
		ConsoleGraphics::DrawCircle(ConsoleGraphics::CicleCoordinate(centre,
			DartBoard::targetRadius(DartBoard::ringRadius(bRadius, outerBullTopRingOffset),
				DartBoard::ringRadius(bRadius, outerBullBottomRingOffset)), i), 2, DartBoard::YELLOW);
	}

	// Draw Bull's Eye Tartget
	ConsoleGraphics::DrawCircle(centre, 4, DartBoard::YELLOW);
		
}

void DartBoard::PrintWindowDims()
{
	RECT windowDims = DartBoard::GetScreenInfo();

	long width = (windowDims.right);
	long height = (windowDims.bottom);

	cout << "Width: " << width << "px" << endl;
	cout << "Height: " << height << "px" << endl;
}

// Private
// =======
RECT DartBoard::GetScreenInfo()
{
	RECT desktopDims;
	HWND hDesktop = GetDesktopWindow();
	
	GetWindowRect(hDesktop, &desktopDims);
	return desktopDims;
}

int DartBoard::setBoardSize(RECT screenInfo)
{
	//int width = screenInfo.right;
	// TODO: Fix this, for now it is forced into 4K mode as wokring on laptop.
	int width = 2600;
	int height = screenInfo.bottom;

	if (width < 2000) {
		return 270;
	}
	else
	{
		return 550;
	}
}

double DartBoard::ringRadius(double boardRadius, double offset)
{
	return (boardRadius - (boardRadius * offset));
}

double DartBoard::targetRadius(double outerRing, double innerRing)
{
	return outerRing + ((innerRing - outerRing) / 2);
}


