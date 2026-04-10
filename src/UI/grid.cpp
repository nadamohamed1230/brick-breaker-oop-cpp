#include "grid.h"
#include "../Core/gameConfig.h"
#include "../Core/game.h"
#include "toolbar.h"
#include "../GameObjects/ball.h"
#include <fstream>



grid::grid(point r_uprleft, int wdth, int hght, game* pG) :
	drawable(r_uprleft, wdth, hght, pG)
{
	rows = height / config.brickHeight;
	cols = width / config.brickWidth;

	brickMatrix = new brick * *[rows];
	for (int i = 0; i < rows; i++)
		brickMatrix[i] = new brick * [cols];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			brickMatrix[i][j] = nullptr;
}


bool grid::isGridEmpty()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (brickMatrix[i][j] != nullptr) {
				return false;
			}
		}
	}
	return true;

}
void grid::loadGame()
{
	ifstream infile("load.txt");

	while (!infile.eof()) {
		int row, col;
		int brickType;
		infile >> row >> col >> brickType;
		BrickType brkType = static_cast<BrickType>(brickType);
		point brickPosition;
		brickPosition.x = col * config.brickWidth;
		brickPosition.y = (row + 2) * config.brickHeight;
		draw();
		addBrick(brkType, brickPosition);
	}
	infile.close();
}

grid::~grid()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (brickMatrix[i][j])
				delete brickMatrix[i][j]; // delete all allocated bricks

	for (int i = 0; i < rows; i++)
		delete brickMatrix[i];

	delete[] brickMatrix;
}



void grid::draw() const
{
	window* pWind = pGame->getWind();
	// draw lines showing the grid
	pWind->SetPen(config.gridLinesColor, 1);

	// draw horizontal lines
	for (int i = 0; i < rows; i++) {
		int y = uprLft.y + (i + 1) * config.brickHeight;
		pWind->DrawLine(0, y, width, y);
	}
	// draw vertical lines
	for (int i = 0; i < cols; i++) {
		int x = (i + 1) * config.brickWidth;
		pWind->DrawLine(x, uprLft.y, x, uprLft.y + rows * config.brickHeight);
	}

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (brickMatrix[i][j])
				brickMatrix[i][j]->draw(); // draw existing bricks
}

void grid::deleteBrick(point clickedPoint)
{
	point corner;

	// Calculate the grid cell index from the clicked point
	int gridCellRowIndex = (clickedPoint.y - uprLft.y) / config.brickHeight;
	int gridCellColIndex = clickedPoint.x / config.brickWidth;

	// Check if the indices are within the valid range
	if (gridCellRowIndex >= 0 && gridCellRowIndex < rows &&
		gridCellColIndex >= 0 && gridCellColIndex < cols)
	{
		// Check if a brick exists at the clicked cell
		if (brickMatrix[gridCellRowIndex][gridCellColIndex])
		{
			corner = brickMatrix[gridCellRowIndex][gridCellColIndex]->getuprlft();
			window* pWind = pGame->getWind();
			// draw lines showing the grid
			pWind->SetPen(config.gridLinesColor, 1);
			pWind->SetBrush(config.bkGrndColor);
			pWind->DrawRectangle(corner.x, corner.y, corner.x + config.brickWidth, corner.y + config.brickHeight, FILLED);

			delete brickMatrix[gridCellRowIndex][gridCellColIndex];
			brickMatrix[gridCellRowIndex][gridCellColIndex] = nullptr;

		}
	}
}

int grid::addBrick(BrickType brkType, point clickedPoint)
{
	int gridCellRowIndex = (clickedPoint.y - uprLft.y) / config.brickHeight;
	int gridCellColIndex = clickedPoint.x / config.brickWidth;

	// 1- Check that the clickedPoint is within the grid range (and return -1)
	if (clickedPoint.x < uprLft.x || clickedPoint.x >= uprLft.x + width ||
		clickedPoint.y < uprLft.y || clickedPoint.y >= uprLft.y + height)
	{
		// Clicked point is outside the grid range
		return NULL;
	}
	// 2- Check that the clickedPoint does not overlap with an existing brick (return 0)
	if (brickMatrix[gridCellRowIndex][gridCellColIndex] != nullptr)
	{
		return NULL;
	}
	// Here we assume that the above checks are passed

	// From the clicked point, find out the index (row,col) of the corresponding cell in the grid

	// Now, align the upper left corner of the new brick with the corner of the clicked grid cell
	point newBrickUpleft;
	newBrickUpleft.x = uprLft.x + gridCellColIndex * config.brickWidth;
	newBrickUpleft.y = uprLft.y + gridCellRowIndex * config.brickHeight;

	switch (brkType)
	{
	case BRK_NRM: // The new brick to add is Normal Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new normalBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_HARD: // The new brick to add is hard Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new hardBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_ROCK: // The new brick to add is hard Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new RockBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_BOMB:
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new bombBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_BRISM:
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new BrismBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_POWER:
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new PowerBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
		// TODO: 
		// handle more types
	}
	return 1;
}

brick* grid::getbrick()
{
	point ball;
	ball.x = pGame->getBall()->getuprlft().x;
	ball.y = pGame->getBall()->getuprlft().y;
	// 1- Check that the clickedPoint is within the grid range (and return -1)
	if (ball.x < uprLft.x || ball.x >= uprLft.x + width - 10 ||
		ball.y < uprLft.y || ball.y >= uprLft.y + height - 10)
	{
		// Clicked point is outside the grid range
		return nullptr;
	}

	int gridCellRowIndex = (ball.y - uprLft.y) / config.brickHeight;
	int gridCellColIndex = ball.x / config.brickWidth;
	return brickMatrix[gridCellRowIndex][gridCellColIndex];


}

int grid::getrows()
{
	return rows;
}

int grid::getcols()
{
	return cols;
}


bool grid::isWindowClear()
{
	int c = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			if (brickMatrix[i][j])
				c += 1;
		}
	if (c > 0)
		return false;
	else
		return true;

}

brick*** grid::getbrickMatrix()
{
	

	return brickMatrix;
}
