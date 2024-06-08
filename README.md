# 539kernel
Creation of an operating system for learning purposes following the [539kernel book](https://539kernel.com/).

> [!WARNING]
> Work in progress

# Table of Contents
1. [Prerequisite](#prerequisite)
2. [Glossary](#glossary)
3. [Assembly Information](#assembly-information)
3. [Resources](#resources)

# Prerequisite

Install [QEMU](https://www.qemu.org/download/).

# Glossary

**Bootloader:** Code that is responsible for loading the main kernel from the disk to the main memory so the kernel can be executed.

**Register:** Small memory inside the processor’s chip. We can store and read data form it, the registers are too small and too fast.

**General purpose registers:** Can store any kind of data. The size of each one is **32 bits**.

**Special purpose registers:** Provided by the architecture for some specific purposes.

**Fat binary *(`FatELF`)*:** Binary format where the software machine code of ***multiple processor architectures are gathered in one binary file*** and the suitable machine code will be loaded on run based on the type of the system’s processor.

**Flat binary:** File which doesn't use any specification, instead, the output is stored as is with no additional information or organization, only the output machine language of our code.

**Object file:** Machine code of a source file, generated by the compiler. It’s not an executable file, and it can be linked with other object files to generate the final executable file.

**Program Counter:** Stores the **memory address** for the instruction that will be executed in the next instruction cycle of the processor.

**Caller:** Function ***which call*** another function.

**Callee:** Function ***which is called*** by the caller.

**`byte` *(b)*:** 8 bits.

**`word` *(w)*:** 16 bits *(2 bytes)*.

**`doubleword` *(d)*:** 32 bits *(4 bytes)*.

**Operating mode:** Specifies the overall picture of the processor.
- *e.g. Maximum size of available registers, the available advanced features for the running operating system, the restrictions and so on.*

**Real mode:** `16-bits` operating mode.

**Protected mode:** `32-bits` operating mode.
- *Ability to deal with `4GB` of main memory.*

**Long mode:** `64-bits` operating mode.
- *Provide more capacity for its users (e.g. Can deal with `16 exabytes` of memory).*

**Process:** Program that is currently running.

**Kernel-mode:** Privilege to do anything. 
- *e.g. access any memory location, access any resource of the system and perform any operation.*

**User-mode:** Restricted environment where the code that runs on it doesn’t have the privilege to perform sensitive actions.

**Current Privilege Level *(CPL)*:** Privilege level of the currently running code.

**Nibble:** Half a byte.

**Flat memory model:** Viewing the memory as an array of contiguous cells.

**Segment:** Store a bunch of related data.

**Code segment:** Store the code of the program under execution.

**Data segment:** Store the data of the program under execution.

**Stack segment:** Store the data of program’s stack.

**Offset:** Reference to a byte.

**Near call *(jump)*:** Any call *(or jump)* to a code inside the same code segment of the caller.

**Far call *(jump)*:** Any call *(or jump)* to a code outside the same code segment of the caller.

**Global descriptor table *(GDT)*:** A data structure which is used by Intel x86-family processors starting with the `80286` for the purpose of defining the characteristics of the various memory areas *(segments)* which are used during program execution, including the **size**, the **base address**, and **access privileges** like write and executable.
- Source: https://www.geeksforgeeks.org/what-is-global-descriptor-table/

**Local descriptor table *(LDT)*:** Same functionality and structure of GDT. But multiple LDT can be defined in the system, and each one of them can be private to a specific process that is currently running on the system, also, multiple running processes can share a single LDT that is considered private for them by the kernel and no other processes can reach this given LDT.

**Logical memory address:** Generated memory address.

**Physical memory address:** Real memory address.

**Segment limit field:** Size of a given segment.

**Descriptor privilege level *(DLP)*:** Privilege level of a given segment.

**Run-time heap:** Region of process’ memory that provides an area for dynamically allocated objects *(e.g. variables)*.

**Run-time stack:** Region of process’ memory that is used to store the values of local variables and function parameters.
- It’s a way to implement **function’s invocation**.

**Event-driven programming:** Paradigm where the program is driven by **events**. It keeps idle and waiting for any event to occur and once an event occurs, the program starts to work by handling this event.

**Handler:** Function dedicated to an event.

**Non-maskable interrupts *(NMI)*:** Type of interrupts that will interrupt the execution of the current code even if the interruption is disabled.

# Assembly information

- `ESI`, `EDI`, `EBP` and `ESP` are considered as general purpose registers in x86 architecture *(according to Intel’s manual)*, they store some important data in some cases, and it’s better to use them carefully if we are forced to.
- **`call` *(Assembly instruction)*:** Used to call a code that resides in a given memory address. 
  - The instruction **pushes** the return address into the stack.
- **`ret` *(Assembly instruction)*:** Used to resume the execution of the caller. 
  - The instruction **gets** the return address from the stack.
- **`jump` *(Assembly instruction)*:** Jumps to the specified memory address, but **doesn’t store the return address in the stack**.
- **`cmp` *(Assembly instruction)*:** Used to compare two values.
- **`je` *(Assembly instruction)*:** Jump if equal.
- **`jne` *(Assembly instruction)*:** Jump if not equal.
- `db`, `dw`, `dd`, `dq`, `dt`, `ddq` and `do` *(NASM pseudoinstructions)* help us to initialize a memory location with some data.
  - `db 'abc', 0`: *Store each value one after another*.
  - `our_variable db 'abc', 0`: *We can use the label `our variable` to refer to the initialized data*.
- **`times` *(NASM pseudoinstruction)*:** Repeat some source line multiple times.
  - `times 5 call print_character_S_with_BIOS`: *Print 'S' five times*.
  - `times 100 db 0`: *Reserves 100 bytes of the memory and fills them with 0*.
- **`$` *(NASM's special expression)*:** Points to the beginning of the **assembly position** of the current source line.
- **`$$` *(NASM's special expression)*:** Points to the beginning of the current **section** of assembly code.
- **`cli` *(clear interrupt flag)*:** Disable interruption *(manipulate the interrupt flag)*.
- **`sti` *(set interrupt flag)*:** Enable the x86 instruction cli *(manipulate the interrupt flag)*.

# Resources
- [A Journey in Creating an Operating System Kernel *(The 539kernel Book)*](https://539kernel.com/A_Journey_in_Creating_an_Operating_System_Kernel_The_539kernel_Book.pdf)