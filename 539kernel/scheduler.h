#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "process.h"

void scheduler_init();
process_t *get_next_process();
void scheduler(int, int, int, int, int, int, int, int, int);
void run_next_process();

#endif