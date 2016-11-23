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
    ASSERT_ANY_THROW(Queue<int> v(MaxSize + 100));
}

TEST(Queue, cant_enqueue_to_full_queue) 
{
    Queue<int> v(2);
    v.enqueue(1);
    v.enqueue(2);
    ASSERT_ANY_THROW(v.enqueue(4));
}

TEST(Queue, cant_dequeue_of_clear_queue)
{
    Queue<int> v(2);
    ASSERT_ANY_THROW(v.dequeue());
}

TEST(Queue, can_dequeue_of_queue)
{
    Queue<int> v(2);
    v.enqueue(1);
    ASSERT_NO_THROW(v.dequeue());
}

TEST(Queue, can_dequeue_of_queue_about_one)
{
    Queue<int> v(5);
    v.enqueue(4);
    EXPECT_EQ(4, v.dequeue());
}

TEST(Queue, can_dequeue_of_queue_about_two)
{
    Queue<int> v(5);
    v.enqueue(4);
    v.enqueue(7);
    EXPECT_EQ(4, v.dequeue());
}

TEST(Queue, can_dequeue_of_queue_about_three)
{
    Queue<int> v(5);
    v.enqueue(4);
    v.enqueue(1);
    v.enqueue(77);
    EXPECT_EQ(4, v.dequeue());
}

TEST(Queue, can_dequeue_twice_of_queue_about_three)
{
    Queue<int> v(5);
    v.enqueue(4);
    v.enqueue(1);
    v.enqueue(77);
    v.dequeue();
    EXPECT_EQ(1, v.dequeue());
}

TEST(Queue, IsEmpty_false_of_full_queue) 
{
    Queue<int> v(2);
    v.enqueue(4);
    v.enqueue(4);
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
    v.enqueue(4);
    ASSERT_FALSE(v.IsEmpty());
}

TEST(Queue, IsFull_true_of_full_queue) 
{
    Queue<int> v(2);
    v.enqueue(4);
    v.enqueue(4);
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
    v.enqueue(4);
    ASSERT_FALSE(v.IsFull());
}