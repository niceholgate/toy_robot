
#include "Table.h"
#include <gtest/gtest.h>

TEST(TestTable, TestTableMethods) {

	/////////// Create a 5x6 Table and check its dimensions
	Table table(5, 6);
	EXPECT_EQ(5, table.getSizeX());
	EXPECT_EQ(6, table.getSizeY());

	/////////// Check isCoordOnTable() results
	EXPECT_TRUE(table.isCoordOnTable(0, 0));
	EXPECT_TRUE(table.isCoordOnTable(2, 3));
	EXPECT_FALSE(table.isCoordOnTable(4, 6));
	EXPECT_FALSE(table.isCoordOnTable(5, 5));
	EXPECT_FALSE(table.isCoordOnTable(-1, -1));
	EXPECT_FALSE(table.isCoordOnTable(-1, 2));
	EXPECT_FALSE(table.isCoordOnTable(2, -1));

	/////////// Check robot placement works
	EXPECT_FALSE(table.placeRobot(8, 2, Direction::NORTH, false));
	EXPECT_EQ(table.getRobot()->getPositionX(), -1);
	EXPECT_EQ(table.getRobot()->getPositionY(), -1);
	EXPECT_TRUE(table.placeRobot(3, 4, Direction::NORTH, false));
	EXPECT_EQ(table.getRobot()->getPositionX(), 3);
	EXPECT_EQ(table.getRobot()->getPositionY(), 4);
}