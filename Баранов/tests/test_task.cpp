#include "task.h"
#include <gtest.h>

TEST(Task, can_create_task_with_positive_length)
{
    ASSERT_NO_THROW(Task t(5));
}

TEST(Task, cant_create_task_with_negative_length)
{
    ASSERT_ANY_THROW(Task t(-5));
}

TEST(Task, cant_create_task_with_zero_length)
{
    ASSERT_ANY_THROW(Task t(0));
}

TEST(Task, cant_create_too_large_task)
{
    ASSERT_ANY_THROW(Task t(MaxSize + 1));
}

TEST(Task, cant_plus_to_full_task)
{
    Task t(1);
    t.plus();
    ASSERT_ANY_THROW(t.plus(););
}


TEST(Task, can_plus_to_task_about_one)
{
    Task t(1);
    ASSERT_NO_THROW(t.plus(););
}

TEST(Task, can_dequeue_of_queue_about_two)
{
    Task t(2);
    t.plus();
    ASSERT_NO_THROW(t.plus(););
}

TEST(Task, can_plus_to_task_about_three)
{
    Task t(3);
    t.plus();
    t.plus();
    ASSERT_NO_THROW(t.plus(););
}

TEST(Task, can_show_need)
{
    Task t(3);
    EXPECT_EQ(3, t.show_need());
}

TEST(Task, can_show_have)
{
    Task t(3);
    EXPECT_EQ(0, t.show_have());
}

TEST(Task, can_show_have_about_one)
{
    Task t(3);
    t.plus();
    EXPECT_EQ(1, t.show_have());
}

TEST(Task, can_show_have_about_two)
{
    Task t(3);
    t.plus();
    t.plus();
    EXPECT_EQ(2, t.show_have());
}

TEST(Task, IsFull_true_of_full_task) 
{
    Task t(2);
    t.plus();
    t.plus();
    ASSERT_TRUE(t.IsFull());
}

TEST(Task, IsFull_false_of_clear_task)
{
    Task t(2);
    ASSERT_FALSE(t.IsFull());
}

TEST(Task, IsFull_false_of_any_task)
{
    Task t(2);
    t.plus();
    ASSERT_FALSE(t.IsFull());
}