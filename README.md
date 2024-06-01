# 539kernel
Creation of an operating system for learning purposes following the [539kernel book](https://539kernel.com/).

# Table of Contents
1. [Glossary](#glossary)
2. [Other Information](#assembly-information)
3. [Resources](#resources)

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

**`doubleword` *(d)*:** 32 bites *(4 bytes)*.

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



# Resources
- [A Journey in Creating an Operating System Kernel *(The 539kernel Book)*](https://539kernel.com/A_Journey_in_Creating_an_Operating_System_Kernel_The_539kernel_Book.pdf)