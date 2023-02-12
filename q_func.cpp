#include "queue.h"

void queue_init (queue* box)
{
    memset (box->data, 0, q_capacity* sizeof (q_type));
    MY_ASSERT (box->data != NULL);
    box->head = 0;
    box->tail = 0;
}

void queue_push (queue* box, int element)
{
    QUEUE_CHECK (box->size != q_capacity);
    box->data[box->tail]    = element;
    box->tail = (box->tail + 1) & q_mask; //increase of tail
    box->size++;
    printf ("%d\n", box->tail);
}

q_type queue_pop (queue* box, int queue_side) // TODO: probably va_args
{
    QUEUE_CHECK (box->size != 0);
    box->size--;
    q_type element = 0;

    if (queue_side == TAIL) // case of taking from the end
    {
        box->tail = (box->tail - 1) & q_mask;
        element   = box->data[box->tail];
        box->data[box->tail] = poison;
        return element;
    }

    else                   //case of taking from the head
    {
        element = box->data[box->head];
        box->data[box->head] = poison;
        box->head = (box->head + 1) & q_mask;
        return element;
    }
}

// void queue_delete (queue* box)
// {
//     free (box->data);
// }
