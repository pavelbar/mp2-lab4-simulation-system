#include "queue.h"
#include <gtest.h>

TEST(Tqueue, can_create_queue_with_positive_length)
{
    ASSERT_NO_THROW(Queue<int> v(5));
}
