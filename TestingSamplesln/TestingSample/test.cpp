#include "pch.h"
#include <iostream>


class Check {
	int value;
public:
	Check() {
		value = 0;
	}
	void setValue(int n) {
		value = n;
	}
	int getValue() {
		return value;
	}
};


TEST(CheckTests, GetValueTest) {
	// Arrange
	Check* check_obj = new Check();

	// Act
	check_obj->setValue(100);

	// Assert
	ASSERT_EQ(check_obj->getValue(), 100);
}



TEST(TestCaseName, TestName) {
  ASSERT_EQ(1, 1);
  ASSERT_TRUE(true);
}

TEST(SampleTests, Test1) {
	ASSERT_TRUE(100 == 100);
}

TEST(SampleTests, Test2) {
	ASSERT_FALSE(1 == 2);
}

