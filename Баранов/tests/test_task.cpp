#include "task.h"
#include "queue.h"
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

TEST(Task, can_get_need)
{
    Task t(3);
    EXPECT_EQ(3, t.get_need());
}
