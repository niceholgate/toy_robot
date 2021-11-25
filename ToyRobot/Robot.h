#ifndef ROBOT_H
#define ROBOT_H

#include "TableInterface.h"
#include <string>

enum class Direction : char
{
	NORTH = 'N',
	SOUTH = 'S',
	EAST = 'E',
	WEST = 'W',
};

class Robot
{

public:


	/* Constructor
	*
	* aTable Pointer to Table associated with this robot
	*/
	Robot(TableInterface* aTable);

	/* Set the robot's position on its Table's coordinate system (can be on or off the Table)
	* 
	* aX X coordinate of location to place robot
	* aY Y coordinate of location to place robot
	*/
	void setPosition(int aX, int aY);

	/* Set the robot's forward-facing direction
	*
	* aDirection Robot's new forward-facing direction
	*/
	void setDirection(Direction aDirection) {
		mDirection = aDirection;
	}

	/* Move the robot forward by one, if possible
	*
	* return Whether the movement succeeded
	*/
	bool move();

	/* Rotate the robot left
	*
	* return Whether the rotation succeeded
	*/
	bool left();

	/* Rotate the robot right
	* 
	* return Whether the rotation succeeded
	*/
	bool right();

	// Get direction arrow character for map
	char getDirectionArrow();

	// Get current X coordinate of robot's location
	int getPositionX() {
		return mPositionX;
	}

	// Get current Y coordinate of robot's location
	int getPositionY() {
		return mPositionY;
	}

	// Get current direction
	Direction getDirection() {
		return mDirection;
	}

	// Get if currently on table
	bool isOnTable() {
		return mIsOnTable;
	}

private:

	// Pointer to Table associated with this robot
	TableInterface* mTable;

	// The direction the robot is facing
	Direction mDirection;

	// Current X position of robot on Table
	int mPositionX;

	// Current Y position of robot on Table
	int mPositionY;

	// Flag true if the robot is currently on the Table
	bool mIsOnTable;
};

#endif // ROBOT_H

