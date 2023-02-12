#include "queue.h"

void queue_dump (queue* box)
{
    int code_of_error = queue_check (box);

    if (code_of_error != 0)
    {
        switch (code_of_error)
        {
            case EMPTY_QUEUE:
                fprintf (stderr, "Impossible to make a pop because queue is empty\n");
                print_queue (box);
                break;

            case OVERFLOWED_QUEUE:
                fprintf (stderr, "Impossible to make a push because queue is overflowed\n");
                print_queue (box);
                break;
        }
    }
}

void print_queue (queue* box)
{
    FILE* print_queue = fopen ("queue.txt", "w");
    MY_ASSERT (print_queue != NULL);

    fprintf (print_queue, "=========================HEAD_&_TAIL====================================\n"
                          "%3d [%d] - head point to this cell\n"
                          "%3d [%d] - tail point to this cell\n"
                          "============================QUEUE=======================================\n\n"
                          ,box->head, box->data[box->head], box->tail, box->data[box->tail]);

    for (int i = 0; i < q_capacity; i++)
    {
        if (i == box->tail)
        {
            if (box->tail == box->head)
            {
                fprintf (print_queue, "%3d [%d] - head & tail point to this cell\n", i, box->data[i]);
            }

            else
            {
                fprintf (print_queue, "%3d [%d] - tail point to this cell\n", i, box->data[i]);
            }
        }

        else if (i == box->head)
        {
            fprintf (print_queue, "%3d [%d] - head point to this cell\n", i, box->data[i]);
        }

        else
        {
            fprintf (print_queue, "%3d [%d]\n", i, box->data[i]);
        }
    }
    fclose (print_queue);
}
