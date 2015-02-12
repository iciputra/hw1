#include "llistint.h"
#include "gtest/gtest.h"

class LListIntTest : public testing::Test {
protected:

	LListIntTest() {
	}

	virtual ~LListIntTest() {		
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:
	virtual void SetUp() {
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);
	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).
	}

	// Objects declared here can be used by all tests in the test case.
	LListInt l1;
};

TEST_F(LListIntTest, L1_values) {
	// Exepct 0th element to be 1, 1st elemnt to be 2, etc.
	for (int i = 0 ; i < 4; i++) {
		EXPECT_EQ(l1.get(i), i + 1);
	}
}

TEST_F(LListIntTest, Assign_Same){
	LListInt l2;
	l2 = l1;
	for (int i = 0 ; i < 4; i++) {
		EXPECT_EQ(l1.get(i), i + 1);
	}
	for (int i = 0 ; i < 4; i++) {
		EXPECT_EQ(l2.get(i), i + 1);
	}
}

TEST_F(LListIntTest, Assign_Changes){
	LListInt l2;
	l2.push_back(3);
	l2 = l1;
	
	l2.set(0, 5);
	EXPECT_EQ(l2.get(0), 5);
	for (int i = 0 ; i < 4; i++) {
		EXPECT_EQ(l1.get(i), i + 1);
	}
	for (int i = 1 ; i < 4; i++) {
		EXPECT_EQ(l2.get(i), i + 1);
	}

	l2.remove(0);
	EXPECT_EQ(l1.size(), 4);
	EXPECT_EQ(l2.size(), 3);
	for (int i = 0 ; i < 4; i++) {
		EXPECT_EQ(l1.get(i), i + 1);
	}
	for (int i = 1 ; i < 3; i++) {
		EXPECT_EQ(l2.get(i), i + 2);
	}
}

TEST_F(LListIntTest, CopyCon_Same){
	LListInt l2(l1);
	for (int i = 0 ; i < 4; i++) {
		EXPECT_EQ(l1.get(i), i + 1);
	}
	for (int i = 0 ; i < 4; i++) {
		EXPECT_EQ(l2.get(i), i + 1);
	}
}

TEST_F(LListIntTest, CopyCon_Changes){
	LListInt l2(l1);
	
	l2.set(0, 5);
	EXPECT_EQ(l2.get(0), 5);
	for (int i = 0 ; i < 4; i++) {
		EXPECT_EQ(l1.get(i), i + 1);
	}
	for (int i = 1 ; i < 4; i++) {
		EXPECT_EQ(l2.get(i), i + 1);
	}

	l2.remove(0);
	EXPECT_EQ(l1.size(), 4);

	for (int i = 1 ; i < 3; i++) {
		EXPECT_EQ(l2.get(i), i + 2);
	}
}

TEST_F(LListIntTest, PushBackTest){
	l1.push_back(5);
	l1.push_back(6);
	EXPECT_EQ(l1.size(), 6);
	for (int i = 0 ; i < 5; i++) {
		EXPECT_EQ(l1.get(i), i + 1);
	}	
}