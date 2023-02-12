#include "queue.h"

int main ()
{
    queue box = {};
    queue_init (&box);

    for (int i = 0; i < q_capacity; i++)
    {
        queue_push (&box, i);
    }

    queue_pop (&box, HEAD);
    queue_pop (&box, HEAD);
    queue_pop (&box, HEAD);
    // for (int i = 0; i <= q_capacity ; i++)
    // {
    //     queue_pop (&box, HEAD);
    // }

    print_queue (&box);
    return 0;
}
