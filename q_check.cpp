#include "queue.h"

int queue_check (queue* box)
{
    if (box->size == 0)
    {
        return EMPTY_QUEUE;
    }

    else if (box->size == q_capacity)
    {
        return OVERFLOWED_QUEUE;
    }
}
