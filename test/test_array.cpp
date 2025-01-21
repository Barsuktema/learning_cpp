#include "container.hpp"
#include <gtest/gtest.h>

TEST(Array, Create) {
    Array<int> arr;
    const size_t expected = 0;
    ASSERT_EQ(arr.size(), expected);
}

TEST(Array, PushBack) {
    Array<int> arr;
    const int count = 10;
    for (size_t i = 0; i < count; ++i){
        arr.push_back(i);
        ASSERT_EQ(arr[i], i);
    }
    ASSERT_EQ(arr.size(), count);
}

TEST(Array, InsertStart) {
    Array<int> arr;
    const int count = 100;
    for (size_t i = 0; i < count; ++i){
        arr.push_back(i);
    }
    arr.insert(100,0);
    ASSERT_EQ(arr[0], 100);

}

TEST(Array, InsertMiddle) {
    Array<int> arr;
    const int count = 100;
    for (size_t i = 0; i < count; ++i){
        arr.push_back(i);
    }
    arr.insert(200,50);
    ASSERT_EQ(arr[50], 200);
    arr.insert(300,100);
    ASSERT_EQ(arr[100], 300);
}

TEST(Array, InsertEnd) {
    Array<int> arr;
    const int count = 100;
    for (size_t i = 0; i < count; ++i){
        arr.push_back(i);
    }
    arr.insert(300,100);
    ASSERT_EQ(arr[100], 300);
}

TEST(Array, EraseStart) {
    Array<int> arr;
    const int count = 100;
    for (size_t i = 0; i < count; ++i){
        arr.push_back(i);
    }
    arr.erase(0);
    EXPECT_TRUE(arr[0] != 0);
}

TEST(Array, EraseMiddle) {
    Array<int> arr;
    const int count = 100;
    for (size_t i = 0; i < count; ++i){
        arr.push_back(i);
    }
    arr.erase(50);
    EXPECT_TRUE(arr[50] != 50);
}

TEST(Array, EraseEnd) {
    Array<int> arr;
    const int count = 100;
    for (size_t i = 0; i < count; ++i){
        arr.push_back(i);
    }
    size_t len = arr.size();
    arr.erase(len-1);
    len = arr.size();
    EXPECT_TRUE(arr.size() < count);
    EXPECT_TRUE(arr[len-1] != count-1);
}

TEST(Array, ReturnValue) {
    Array<int> arr;
    const int count = 10;
    for (size_t i = 0; i < count; ++i){
        arr.push_back(i);
        ASSERT_EQ(arr[i], i);
    }
}

TEST(Array, Size) {
    Array<int> arr;
    const int count = 100;
    for (size_t i = 0; i < count; ++i){
        arr.push_back(i);
    }
    ASSERT_EQ(arr.size(), count);
}