#include "container.hpp"
#include <gtest/gtest.h>

TEST(List, Create) {
    List<int> list;
    const size_t expected = 0;
    ASSERT_EQ(list.size(), expected);
}

TEST(List, PushBack) {
    List<int> list;
    const int count = 10;
    for (size_t i = 0; i < count; ++i){
        list.push_back(i);
        ASSERT_EQ(list[i], i);
    }
    ASSERT_EQ(list.size(), count);
}

TEST(List, InsertStart) {
    List<int> list;
    const int count = 100;
    for (size_t i = 0; i < count; ++i){
        list.push_back(i);
    }
    list.insert(100,0);
    ASSERT_EQ(list[0], 100);

}

TEST(List, InsertMiddle) {
    List<int> list;
    const int count = 100;
    for (size_t i = 0; i < count; ++i){
        list.push_back(i);
    }
    list.insert(200,50);
    ASSERT_EQ(list[50], 200);
    list.insert(300,100);
    ASSERT_EQ(list[100], 300);
}

TEST(List, InsertEnd) {
    List<int> list;
    const int count = 100;
    for (size_t i = 0; i < count; ++i){
        list.push_back(i);
    }
    list.insert(300,100);
    ASSERT_EQ(list[100], 300);
}

TEST(List, EraseStart) {
    List<int> list;
    const int count = 100;
    for (size_t i = 0; i < count; ++i){
        list.push_back(i);
    }
    list.erase(0);
    EXPECT_TRUE(list[0] != 0);
}

TEST(List, EraseMiddle) {
    List<int> list;
    const int count = 100;
    for (size_t i = 0; i < count; ++i){
        list.push_back(i);
    }
    list.erase(50);
    EXPECT_TRUE(list[50] != 50);
}

TEST(List, EraseEnd) {
    List<int> list;
    const int count = 100;
    for (size_t i = 0; i < count; ++i){
        list.push_back(i);
    }
    size_t len = list.size();
    list.erase(len-1);
    len = list.size();
    EXPECT_TRUE(list.size() < count);
    EXPECT_TRUE(list[len-1] != count-1);
}

TEST(List, ReturnValue) {
    List<int> list;
    const int count = 10;
    for (size_t i = 0; i < count; ++i){
        list.push_back(i);
        ASSERT_EQ(list[i], i);
    }
}

TEST(List, Size) {
    List<int> list;
    const int count = 100;
    for (size_t i = 0; i < count; ++i){
        list.push_back(i);
    }
    ASSERT_EQ(list.size(), count);
}