#include "Table.h"
#include "TableInterface.h"
#include "Robot.h"
#include <gtest/gtest.h>

TEST(TestRobot, TestRobotMethods) {

	/////////// Create a 5x5 Table (just to pass by reference to the test Robot)
	/////////// and the test Robot itself
	Table table = Table(5, 5);
	Table* table_ptr = &table;
	TableInterface* table_interface = (TableInterface*)table_ptr;
	Robot robot = Robot(table_interface);
	
	/////////// Test setting position and isOnTable()
	robot.setPosition(6, 3);
	EXPECT_FALSE(robot.isOnTable());
	robot.setPosition(2, 3);
	EXPECT_TRUE(robot.isOnTable());

	/////////// Test setting direction
	robot.setDirection(Direction::WEST);
	EXPECT_EQ(robot.getDirection(), Direction::WEST);

	/////////// Test left()
	EXPECT_TRUE(robot.left());
	EXPECT_EQ(robot.getDirection(), Direction::SOUTH);
	EXPECT_TRUE(robot.left());
	EXPECT_EQ(robot.getDirection(), Direction::EAST);
	EXPECT_TRUE(robot.left());
	EXPECT_EQ(robot.getDirection(), Direction::NORTH);
	EXPECT_TRUE(robot.left());
	EXPECT_EQ(robot.getDirection(), Direction::WEST);
	// Test command ignored if not on Table
	robot.setPosition(7, 3);
	EXPECT_FALSE(robot.left());
	EXPECT_EQ(robot.getDirection(), Direction::WEST);

	/////////// Test right()
	robot.setPosition(2, 3);
	EXPECT_TRUE(robot.right());
	EXPECT_EQ(robot.getDirection(), Direction::NORTH);
	EXPECT_TRUE(robot.right());
	EXPECT_EQ(robot.getDirection(), Direction::EAST);
	EXPECT_TRUE(robot.right());
	EXPECT_EQ(robot.getDirection(), Direction::SOUTH);
	EXPECT_TRUE(robot.right());
	EXPECT_EQ(robot.getDirection(), Direction::WEST);
	// Test command ignored if not on Table
	robot.setPosition(7, 3);
	EXPECT_FALSE(robot.right());
	EXPECT_EQ(robot.getDirection(), Direction::WEST);

	/////////// Test move()
	robot.setPosition(2, 3);
	// Test command works twice only (after two moves, on W boundary)
	EXPECT_TRUE(robot.move());
	EXPECT_TRUE(robot.move());
	EXPECT_FALSE(robot.move());
	EXPECT_EQ(robot.getPositionX(), 0);
	EXPECT_EQ(robot.getPositionY(), 3);
	// Test command works thrice more only (after three moves, in SW corner)
	EXPECT_TRUE(robot.left());
	EXPECT_TRUE(robot.move());
	EXPECT_TRUE(robot.move());
	EXPECT_TRUE(robot.move());
	EXPECT_FALSE(robot.move());
	EXPECT_EQ(robot.getPositionX(), 0);
	EXPECT_EQ(robot.getPositionY(), 0);
}