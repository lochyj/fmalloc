// - Copyright -------------------------------------------------------------------|
// Copyright (c) 2023 Lachlan Jowett.                                             |
// Please refer to the license located in 'LICENSE' for permissions and liability.|
// -------------------------------------------------------------------------------|

#include "fmalloc.h"

void* stack_bottom;
void* stack_end;
void* stack_top;

int main(int argc, char** argv) {

    // Because we cannot access the real stack, we need to create a fake one.
    // It will however be a subset of the real stack so it will do.
    // Initially we will allocate 1MB of memory for the stack.
    uintptr_t* fake_stack = (uintptr_t *) malloc(STACK_SIZE);

    stack_bottom = fake_stack;
    stack_end = fake_stack + STACK_SIZE;

    // This will change as we allocate memory.
    stack_top = stack_bottom;

    char* test = (char*) fmalloc(10);

    *test = 'H';

    printf("%c\n", *test);

    free((void*) fake_stack);

    return 0;
}

void* fmalloc(size_t size) {
    void* location = stack_top;

    if (stack_top + size > stack_end) {
        // PANIC we are out of fake memory. In reality we can just swap out some pages but we can't do that in this app. TODO: Handle this in kernel.
        return NULL;
    }

    stack_top += size;

    return location;
}
