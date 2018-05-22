# Does it have operation system ?
- manage resource
    - memory
    - processor
    - hardware devices
- providing abstractions
    - interface easy to use
    - to programs run on device
    - interpret

- Apple II
    - run assembly code on it

# Kernel Privileges
- What can the kernel(supervisor) do that user-level programs cannot ?
    - CPU
        - (kernel has special access to the CPU)
        - handle kernel timer interrupts
        - interfere

    - memory
        - malloc() vs kmalloc()
        - kernel can control memory, regular program can n        - when user program try to allowed memory, process will give SEGFAULT instead
        - some instruction can any program can execute. others are privilege instructions(kernel).
        - test instruction by low-level language
        - load the GDT an load the LDT register mean.

    - intel page 2025: 16 privileged instruction
        - share cpu time and memory
        - all these instructions with Global Descriptior in the GDT. and Local Descriptior(memory space)
        -  CRO(4 control register) runing in protected mode.If user program could turn that bit to zero, they can do every thing they want.
        - X86 protection Rings
            - There's nothing magic here. just 2 bits in a register that determine what instructions can execute!

# Outline
    - How virtualBox Really Works
    - Browser Processes
    - Demo PS2
        - Shell, Pipes, Redirects

    - The kernel is able to see the kernel interrupt
