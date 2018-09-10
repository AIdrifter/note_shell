# 
#
## Closure Compiler
profile performance => java scripts => jit

## linker
- relocation
- static linker and dynmic linking(linux)
                           DLL    (windows)
## signal
- ctrl + c => send signal to interrupt process 

## network programming

## dynamic memory
malloc() free()

# moderm cpu
C       P         I
cycle
            HT
4 core ----------> 8 core


SMT simulatneous multi threading


# system value
undeifined behavior

1.overlfow when mutiple twice
         (x*2)                         / 2
so (x*2)/2 != x

2.compiler optimzie x

# CSAP
ch2, 3 , 6, 9

# memory
memory aligment and instruction fetch

```C
#include <stdint.h>
#include <stddef.h>
uint8_t unaligned_get8(void *src) {
    uintptr_t csrc = (uintptr_t) src;
    uint32_t v = *(uint32_t *) (csrc & 0xfffffffc);
    v = (v >> (((uint32_t)csrc & 0x3) * 8)) & 0x000000ff;
    return v;


# gcc optimize bug


## big LITTLE
## Strong middle little core

cpu gpu asic ---- AI

        dsp


# Arm level
Calss Application
      Realtime (automotive)
      Micro-controller


# SCU
# IOMMU
1.PA <-> VA
2.hardware IP : MMU 400
3.componentconnect to component : network interconnect
4.NIC-400
5.DMA-330 : ARM (ACP)
6.CCI : Cache Choherent Interconnect
    wait to another hardware IP.........boy and girl firends
    total core  < 4 core
    ARM dynmaicIQ <-> hardware scheduler for core scheduling
                   -> saved power consumption
                   -> AI chip move to core scheduling place
    gross will become large after two months
# GPU
mali
vertex shader. pixel shader
GLSL : open GL control shader language
GPGPU : Gernal Purpose CPU
T628 Support IOMMU

# Cortex A53 vs cortex A57
Dispatch high cost => How to Improve it.

# big LITTLE
ARM visor

# Task Scheduling based on cluster migration
1.CUP hot plug


# paramter(value 1 2 3..) and argument( special sequence )
fun(1,2,3)

# angry birds
lua jit

# ABI : Allocation Binary Interface
for multiple language to communication.

# GOT : big table                big jump
# PLT : small table(cache)       small jump


# Just in time compiler
slow and accepted

## jit
mmap

      RWX
VA<------------>PA

__clear_cache()      make sure chache chohereance


# genric.h // without relationship between platform
typeof() // 1.gnu extension 2.operator
google: get_unaligned_le32 generic

# OS
concurrency operating systemt
