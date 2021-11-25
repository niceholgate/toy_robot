#ifndef TABLE_H
#define TABLE_H

#include "TableInterface.h"
#include "Robot.h"


class Table : TableInterface
{
public:
	
	/* Constructor
	*
	* aSizeX X size of Table
	* aSizeY Y size of Table
	*/
	Table(int aSizeX, int aSizeY);

	//////////////////////////////////////
	// TableInterface methods
	virtual bool isCoordOnTable(int X, int Y) override;

	//////////////////////////////////////
	// Additional public methods
	
	// Get X size of Table
	int getSizeX();

	// Get Y size of Table
	int getSizeY();

	/* Place the robot at a specified location on the Table
	*
	* aX X coordinate of location to place robot
	* aY Y coordinate of location to place robot
	* message Whether to display message of placement details in IO
	* 
	* return Whether the placement was possible
	*/
	bool placeRobot(int aX, int aY, Direction aDirection, bool message = true);

	/* Report to standard out the coordinates and rotation of the robot,
	* and also print a visual map of the table + robot
	* (prints by default but can turn off with aShowMap).
	*
	* aSuppressMap Whether to print the map, defaults to true
	*/
	void report(bool aShowMap = true);

	Robot* getRobot() {
		return &mRobot;
	}

private:

	// Helper to print the report map, if requested
	void printMap();

	// Robot on this table (have assumed there is only one)
	Robot mRobot;

	// X size of the table
	int mSizeX;

	// Y size of the table
	int mSizeY;

};


#endif // TABLE_H