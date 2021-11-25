#include "Robot.h"

Robot::Robot(TableInterface* aTable) :
	mTable(aTable),
	mPositionX(),
	mPositionY()
{
	// The robot begins off the table, facing north
	mPositionX = -1;
	mPositionY = -1;
	mDirection = Direction::NORTH;
}

void Robot::setPosition(int aX, int aY) {
	mPositionX = aX;
	mPositionY = aY;
	mIsOnTable = mTable->isCoordOnTable(aX, aY);
}

bool Robot::move() {
	int next_X = mPositionX;
	int next_Y = mPositionY;

	switch (mDirection) {
		case Direction::NORTH:
			next_Y += 1;
			break;
		case Direction::SOUTH:
			next_Y -= 1;
			break;
		case Direction::EAST:
			next_X += 1;
			break;
		case Direction::WEST:
			next_X -= 1;
			break;
	}

	if (mTable->isCoordOnTable(next_X, next_Y)) {
		mPositionX = next_X;
		mPositionY = next_Y;
		return true;
	}
	return false;
}

bool Robot::left() {
	if (mIsOnTable) {
		switch (mDirection) {
			case Direction::NORTH:
				mDirection = Direction::WEST;
				break;
			case Direction::SOUTH:
				mDirection = Direction::EAST;
				break;
			case Direction::EAST:
				mDirection = Direction::NORTH;
				break;
			case Direction::WEST:
				mDirection = Direction::SOUTH;
				break;
		}
		return true;
	}
	return false;
}

bool Robot::right() {
	if (mIsOnTable) {
		switch (mDirection) {
		case Direction::NORTH:
			mDirection = Direction::EAST;
			break;
		case Direction::SOUTH:
			mDirection = Direction::WEST;
			break;
		case Direction::EAST:
			mDirection = Direction::SOUTH;
			break;
		case Direction::WEST:
			mDirection = Direction::NORTH;
			break;
		}
		return true;
	}
	return false;
}

char Robot::getDirectionArrow() {
	switch (mDirection) {
	case Direction::NORTH:
		return '^';
	case Direction::SOUTH:
		return 'v';
	case Direction::EAST:
		return '>';
	case Direction::WEST:
		return '<';
	}
}



