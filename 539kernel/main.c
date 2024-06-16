#include "screen.h"
#include "scheduler.h"

// void simulatedProcess(char[], char[]); // Need to change process_create to allow one function to create different processes
void processA();
void processB();
void processC();
void processD();

void kernel_main() {
    process_t p1, p2, p3, p4;

    screen_init();
    process_init();
    scheduler_init();

    print("Welcome to 539kernel!");
    println();
    print("We are now in Protected-mode ");
    println();
    printi(539);
    println();

    process_create(&processA, &p1);
    process_create(&processB, &p2);
    process_create(&processC, &p3);
    process_create(&processD, &p4);

    while(1);
}

void interrupt_handler(int interrupt_number) {
    println();
    print("Interrupt Received ");
    printi(interrupt_number);
}
/*
void simulatedProcess(char processName[], char asmInstruction[]) {
    print("Process ");
    print(processName);
    print(",");

    while(1) {
        asm ( asmInstruction );
    }
}*/

void processA() {
    print("Process A,");

    while (1) {
        asm("mov $5390, %eax");
    }
}

void processB() {
    print("Process B,");

    while (1) {
        asm("mov $5391, %eax");
    }
}

void processC() {
    print("Process C,");

    while (1) {
        asm("mov $5392, %eax");
    }
}

void processD() {
    print("Process D,");

    while (1) {
        asm("mov $5393, %eax");
    }
}