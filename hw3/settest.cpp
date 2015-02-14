#include "setint.h"
#include "gtest/gtest.h"

class SetIntTest : public testing::Test {
protected:

	SetIntTest() {
	}

	virtual ~SetIntTest() {		
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:
	virtual void SetUp() {
		l1.insert(1);
		l1.insert(2);
		l1.insert(3);
		l1.insert(4);
	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).
	}
	SetInt l1;
	// Objects declared here can be used by all tests in the test case.
};

TEST_F(SetIntTest, l1Values) {
	// Exepct 0th element to be 1, 1st elemnt to be 2, etc.
	    int const* yea = l1.first();
    	EXPECT_EQ(*yea, 1);
    	for (int i = 1; i < l1.size(); i++){
    		int const* yes = l1.next();
    		EXPECT_EQ(*yes, i+1);
        }
}

TEST_F(SetIntTest, setUnionTest){
		SetInt l2;
		SetInt l3;
		l2.insert(5);
		l2.insert(6);
		l2.insert(7);
		l2.insert(8);
		l3 = l1.setUnion(l2);

		//check l1 vals still same
		int const* list1 = l1.first();
    	EXPECT_EQ(*list1, 1);
    	for (int i = 1; i < l1.size(); i++){
    		int const* lis1 = l1.next();
    		EXPECT_EQ(*lis1, i+1);
        }
 
        //check l2 vals still same
        int const* list2 = l2.first();
    	EXPECT_EQ(*list2, 5);
    	int x = 5;
    	for (int j = 1; j < l2.size(); j++){
    		int const* lis2 = l2.next();
    		x = x + 1;
    		EXPECT_EQ(*lis2, x);
        }

        //check l3 vals
        int const* list3 = l3.first();
        EXPECT_EQ(*list3, 1);
        for (int i = 1; i < l3.size(); i++){
    		int const* lis3 = l3.next();
    		EXPECT_EQ(*lis3, i+1);
        }
}

TEST_F(SetIntTest, UnionOperatorTest){
		SetInt l2;
		SetInt l3;
		l2.insert(5);
		l2.insert(6);
		l2.insert(7);
		l2.insert(8);
		l3 = l1 | l2;

		//check l1 vals still same
		int const* list1 = l1.first();
    	EXPECT_EQ(*list1, 1);
    	for (int i = 1; i < l1.size(); i++){
    		int const* lis1 = l1.next();
    		EXPECT_EQ(*lis1, i+1);
        }
 
        //check l2 vals still same
        int const* list2 = l2.first();
    	EXPECT_EQ(*list2, 5);
    	int x = 5;
    	for (int j = 1; j < l2.size(); j++){
    		int const* lis2 = l2.next();
    		x = x + 1;
    		EXPECT_EQ(*lis2, x);
        }

        //check l3 vals
        int const* list3 = l3.first();
        EXPECT_EQ(*list3, 1);
        for (int i = 1; i < l3.size(); i++){
    		int const* lis3 = l3.next();
    		EXPECT_EQ(*lis3, i+1);
        }
}

TEST_F(SetIntTest, setintersectionTest){
		SetInt l2;
		SetInt l3;
		l2.insert(7);
		l2.insert(1);
		l2.insert(2);
		l2.insert(3);
        l3 = l1.setIntersection(l2);


		//check l1 vals still same
		int const* list1 = l1.first();
    	EXPECT_EQ(*list1, 1);
    	for (int i = 1; i < l1.size(); i++){
    		int const* lis1 = l1.next();
    		EXPECT_EQ(*lis1, i+1);
        }
 
        //check l2 vals still same
        int const* list2 = l2.first();
    	EXPECT_EQ(*list2, 7);
    	int const* lis2 = l2.next();
    	EXPECT_EQ(*lis2, 1);
    	lis2 = l2.next();
    	EXPECT_EQ(*lis2, 2);
    	lis2 = l2.next();
    	EXPECT_EQ(*lis2, 3);

        //check l3 vals
        int const* list3 = l3.first();
        EXPECT_EQ(*list3, 1);
        for (int i = 1; i < l3.size(); i++){
    		int const* lis3 = l3.next();
    		EXPECT_EQ(*lis3, i+1);
        }
}

TEST_F(SetIntTest, intersect_OperationTest){
		SetInt l2;
		SetInt l3;
		l2.insert(7);
		l2.insert(1);
		l2.insert(2);
		l2.insert(3);
        l3 = l1 & l2;


		//check l1 vals still same
		int const* list1 = l1.first();
    	EXPECT_EQ(*list1, 1);
    	for (int i = 1; i < l1.size(); i++){
    		int const* lis1 = l1.next();
    		EXPECT_EQ(*lis1, i+1);
        }
 
        //check l2 vals still same
        int const* list2 = l2.first();
    	EXPECT_EQ(*list2, 7);
    	int const* lis2 = l2.next();
    	EXPECT_EQ(*lis2, 1);
    	lis2 = l2.next();
    	EXPECT_EQ(*lis2, 2);
    	lis2 = l2.next();
    	EXPECT_EQ(*lis2, 3);

        //check l3 vals
        int const* list3 = l3.first();
        EXPECT_EQ(*list3, 1);
        for (int i = 1; i < l3.size(); i++){
    		int const* lis3 = l3.next();
    		EXPECT_EQ(*lis3, i+1);
        }
}