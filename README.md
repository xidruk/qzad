# Qzkad Memory Manager v1

Qzkad Memory Manager (`qzkad_v1`) is a C function that unifies standard memory allocation and deallocation functions (`malloc`, `calloc`, `realloc`, `free`) into a single interface. This allows for streamlined memory management with improved feedback and professional handling of errors.

## Features

- Unified interface for memory management operations.
- Clear status and detailed messages for each operation.
- Flexible handling of memory (allocate, reallocate, and free).
- Professional and customizable output for better user control.

## Installation

Include `qzkad_v1.h` and `qzkad_v1.c` in your project or copy the code directly from this repository.

## Usage

### Function Prototype

```c
typedef struct {
    void *ptr;
    int status; // 0 for success, -1 for failure
    char message[100]; // Detailed message
} QzkadResult;

QzkadResult qzkad_v1(int operation, void *ptr, size_t num, size_t size);

