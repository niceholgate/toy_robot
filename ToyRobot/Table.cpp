#include "Table.h"
#include <iostream>

Table::Table(int aSizeX, int aSizeY) :
	mRobot(this),
	mSizeX(aSizeX),
	mSizeY(aSizeY)
{

}

int Table::getSizeX() {
	return mSizeX;
}

int Table::getSizeY() {
	return mSizeY;
}

bool Table::isCoordOnTable(int aX, int aY) {
	return aX >= 0 && aX < mSizeX && aY >= 0 && aY < mSizeY;
}

bool Table::placeRobot(int aX, int aY, Direction aDirection, bool message) {
	if (message) {
		std::cout << "Placing robot at position and direction (X, Y, F): (";
		std::cout << aX << ", ";
		std::cout << aY << ", ";
		std::cout << static_cast<char>(aDirection) << ")\n\n";
	}
	if (isCoordOnTable(aX, aY)) {
		mRobot.setDirection(aDirection);
		mRobot.setPosition(aX, aY);
		return true;
	}
	return false;
}

void Table::report(bool aShowMap) {
	const char* on_table_str = mRobot.isOnTable() ? "" : "NOT ";
	std::cout << "The robot IS " << on_table_str << "on the table.\n";
	std::cout << "Robot position and direction (X, Y, F): (";
	std::cout << mRobot.getPositionX() << ", ";
	std::cout << mRobot.getPositionY() << ", ";
	std::cout << static_cast<char>(mRobot.getDirection()) << ")\n\n";
	if (aShowMap) printMap();
}

void Table::printMap() {;
	std::string row_string;
	char grid_marker;
	for (int row = getSizeY() - 1; row > -1; row--) {
		row_string = "| ";
		for (int col = 0; col < getSizeX(); col++) {
			grid_marker = '-';
			if (col == mRobot.getPositionX() && row == mRobot.getPositionY()) {
				grid_marker = mRobot.getDirectionArrow();
			}
			row_string += grid_marker;
			row_string += " |";
			if (col != getSizeX() - 1) row_string += ' ';
		}
		std::cout << row_string << '\n';
	}
	std::cout << '\n';
}



