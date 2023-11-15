#include <gtest/gtest.h>
#include "allocator.h"
#include "ForwardIterator.h"
#include "ConstForwardIterator.h"
#include "unidirectionalList.h"

class unidirectionList : public ::testing::Test{
protected:
    void SetUp() override{
    }
    void TearDown() override{}
    unidirectionalList<int, MapAllocator<std::pair<const int, int>>> list{};
};

TEST_F(unidirectionList, push_back){
    int a = 10;
    list.push_back(a);

    int res = list.begin()->get_value();

    ASSERT_EQ(10, res);
}

TEST_F(unidirectionList, size){
    int a = 10;
    list.push_back(a);

    int res = list.size();

    ASSERT_EQ(1, res);
}