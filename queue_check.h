#if defined(CHECK_QUEUE)
#define QUEUE_CHECK(condition)                                                                     \
        if (!(condition))                                                                                \
        {                                                                                                \
            queue_dump(box);\
            exit (1);\
        }                                                                                                \

#else
#define QUEUE_CHECK;

#endif
