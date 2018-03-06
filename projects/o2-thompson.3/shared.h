#pragma once
#ifndef O2_THOMPSON_3_SHARED_H
#define O2_THOMPSON_3_SHARED_H

#include <unistd.h>

#define SHARED_MEM_KEY 52111
#define QUEUE_KEY 72417
#define MASTER_ID 777

typedef struct Process {
    int pidIndex;
    pid_t actualPid;
} Process;

typedef struct SharedMemoryClock {
    int seconds;
    int nanoSeconds;
} SharedMemoryClock;

typedef struct Message {
    long messageType;
    int childId;
    int isDone;
    int seconds;
    int nanoSeconds;
} Message;


#endif //O2_THOMPSON_3_SHARED_H
