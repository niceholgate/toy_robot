#ifndef TABLE_INTERFACE_H
#define TABLE_INTERFACE_H

// TableInterface to
// allow robot to access its parent's public methods

class TableInterface 
{
public:
	// Check if a given coordinate is on the Table
	virtual bool isCoordOnTable(int X, int Y) = 0;
};

#endif // TABLE_INTERFACE_H