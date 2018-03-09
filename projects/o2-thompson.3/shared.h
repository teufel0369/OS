#pragma once
#ifndef O2_THOMPSON_3_SHARED_H
#define O2_THOMPSON_3_SHARED_H

#include <unistd.h>

#define SHARED_MEM_KEY 10101775
#define QUEUE_KEY 76251
#define MASTER_ID 777

typedef struct ProcessStruct {
    int pidIndex;
    pid_t actualPid;
} ProcessType;

typedef struct SharedMemoryClockStruct {
    int seconds;
    int nanoSeconds;
} SharedMemoryClockType;

typedef struct MessageStruct {
    long messageType;
    int childId;
    int isDone;
    int seconds;
    int nanoSeconds;
} MessageType;

#endif //O2_THOMPSON_3_SHARED_H
