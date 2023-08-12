// - Copyright -------------------------------------------------------------------|
// Copyright (c) 2023 Lachlan Jowett.                                             |
// Please refer to the license located in 'LICENSE' for permissions and liability.|
// -------------------------------------------------------------------------------|

#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 1024 * 1024

void* fmalloc(size_t size);
