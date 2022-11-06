#include "gtest/gtest.h"
#include "../src/TMyVector.h"

TEST(TMyVector, GetSize) {
    TMyVector<int> vec(15);
    EXPECT_EQ(vec.GetSize(), 0);
}

TEST(TMyVector, GetReservSize) {
    TMyVector<int> vec(15);
    EXPECT_EQ(vec.GetReservSize(), 15);
}

TEST(TMyVector, Insert) {
    TMyVector<int> vec(15);
    EXPECT_EQ(vec.GetSize(), 0);
    EXPECT_EQ(vec.GetReservSize(), 15);

    vec.Insert(0, 10); // 10
    vec.Insert(0, 1); // 1 10
    vec.Insert(1, 23); // 1 23 10
    vec.Insert(3, 43); // 1 23 10 43

    EXPECT_EQ(vec.GetValue(0), 1);
    EXPECT_EQ(vec.GetValue(1), 23);
    EXPECT_EQ(vec.GetValue(2), 10);
    EXPECT_EQ(vec.GetValue(3), 43);
}

int main()
{
    testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}