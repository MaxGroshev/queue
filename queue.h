#pragma once
#define DEBUG
#define CHECK_QUEUE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_check.h"
#include "my_ASSERT.h"

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

typedef int q_type; // type of elem in queue

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

static const short q_capacity = 1024; // size of queue is power of 2
static const short q_mask     = 1023; // mask for bin operation is equal to (2^n - 1)
static const int   poison     = 0xCEA;

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

enum queue_side
{
    TAIL = 1,
    HEAD = 2,
};

enum code_of_errors
{
    EMPTY_QUEUE      = -1,
    OVERFLOWED_QUEUE = -2,
};

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

struct queue
{
    q_type         data[q_capacity];
    unsigned short head;
    unsigned short tail;
    size_t         size;
};

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

void   queue_init   (queue* box);
void   queue_push   (queue* box, int element);
q_type queue_pop    (queue* box, int queue_side);
void   print_queue  (queue* box);
int    queue_check  (queue* box);
void   queue_dump   (queue* box);
void   queue_delete (queue* box);


