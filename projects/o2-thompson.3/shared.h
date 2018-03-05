#ifndef O2_THOMPSON_3_SHARED_H
#define O2_THOMPSON_3_SHARED_H

#define DEFAULT_MAX_CHILDREN 5
#define DEFAULT_FILENAME "test.out"
#define DEFAULT_TIMER_SECS 20

typedef struct SharedClock {
    int seconds;
    int nanoSeconds;
} SharedClock;

typedef struct Message {
    long mtype;

    int childId;
    int doneFlag;
    int seconds;
    int nanoSeconds;
} Message;

typedef struct Process {
    int logical;
    pid_t literal;
} Process;

extern Process *pid;
extern SharedClock *shm;
extern int maxChildren;
extern int maxChildren;
extern int shmid;
extern int qid;
extern char filename[64];
void displayHelpOptions();
void masterSignalHandler(int signo);

#endif //O2_THOMPSON_3_SHARED_H
