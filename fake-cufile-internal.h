#ifndef FAKE_CUFILE_H
#define FAKE_CUFILE_H

#include <cuda_runtime.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define WARN(msg) printf(msg"\n");

#define FMAGIC 4711

struct fake_dev_memory{
  size_t size;
  memAttachKind type;
  int magic;
  char padding[4096 - 8 - 4 -4];
  char buf[];
};

fake_dev_memory* fake_get_mem(void * buf);



#endif
