//---
#include "queue.h"
#include <gtest.h>

TEST(Tqueue, can_create_queue_with_positive_length)
{
    ASSERT_NO_THROW(Queue<int> v(5));
}

TEST(Queue, cant_create_queue_with_negative_length)
{
    ASSERT_ANY_THROW(Queue<int> v(-5));
}

TEST(Queue, cant_create_queue_with_zero_length) 
{
    ASSERT_ANY_THROW(Queue<int> v(0));
}

TEST(Queue, cant_create_too_large_queue) 
{
    ASSERT_ANY_THROW(Queue<int> v(MaxSize + 1));
}

TEST(Queue, cant_push_to_full_queue) 
{
    Queue<int> v(2);
    v.push(1);
    v.push(2);
    ASSERT_ANY_THROW(v.push(4));
}

TEST(Queue, cant_pop_of_clear_queue) 
{
    Queue<int> v(2);
    ASSERT_ANY_THROW(v.pop());
}

TEST(Queue, cant_top_of_clear_queue) 
{
    Queue<int> v(2);
    ASSERT_ANY_THROW(v.top());
}

//
//TEST(Queue, can_top_of_queue_about_one)
//{
//    Queue<int> v(5);
//    v.push(4);
//    EXPECT_EQ(4, v.top());
//}
//
//TEST(Queue, can_top_of_queue_about_two)
//{
//    Queue<int> v(5);
//    v.push(4);
//    v.push(7);
//    EXPECT_EQ(7, v.top());
//}
//
//TEST(Queue, can_top_of_queue_about_three)
//{
//    Queue<int> v(5);
//    v.push(4);
//    v.push(1);
//    v.push(77);
//    EXPECT_EQ(77, v.top());
//}

TEST(Queue, can_pop_of_queue_about_one)
{
    Queue<int> v(5);
    v.push(4);
    EXPECT_EQ(4, v.pop());
}

TEST(Queue, can_pop_of_queue_about_two)
{
    Queue<int> v(5);
    v.push(4);
    v.push(7);
    EXPECT_EQ(7, v.pop());
}

TEST(Queue, can_pop_of_queue_about_three)
{
    Queue<int> v(5);
    v.push(4);
    v.push(1);
    v.push(77);
    EXPECT_EQ(77, v.pop());
}

//TEST(Queue, can_push_and_pop) 
//{
//    Queue<int> v(5);
//    v.push(4);
//    v.push(5);
//    EXPECT_EQ(5, v.pop());
//    EXPECT_EQ(4, v.top());
//}

TEST(Queue, IsEmpty_false_of_full_queue) 
{
    Queue<int> v(2);
    v.push(4);
    v.push(4);
    ASSERT_FALSE(v.IsEmpty());
}

TEST(Queue, IsEmpty_true_of_clear_queue) 
{
    Queue<int> v(2);
    ASSERT_TRUE(v.IsEmpty());
}

TEST(Queue, IsEmpty_false_of_any_queue)
{
    Queue<int> v(2);
    v.push(4);
    ASSERT_FALSE(v.IsEmpty());
}

TEST(Queue, IsFull_true_of_full_queue) 
{
    Queue<int> v(2);
    v.push(4);
    v.push(4);
    ASSERT_TRUE(v.IsFull());
}

TEST(Queue, IsFull_false_of_clear_queue)  
{
    Queue<int> v(2);
    ASSERT_FALSE(v.IsFull());
}

TEST(Queue, IsFull_false_of_any_queue)  
{
    Queue<int> v(2);
    v.push(4);
    ASSERT_FALSE(v.IsFull());
}