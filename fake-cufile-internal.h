#ifndef FAKE_CUFILE_H
#define FAKE_CUFILE_H

#include <cuda_runtime.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WARN(msg) printf(msg"\n");

typedef struct {
  int magic;
  size_t size;
  char buf [];
} fake_dev_memory;

fake_dev_memory* fake_get_mem(void * buf);

#endif
