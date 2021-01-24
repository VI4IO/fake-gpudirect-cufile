#ifndef FAKE_CUFILE_H
#define FAKE_CUFILE_H

#include <cuda_runtime.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define WARN(msg) printf(msg"\n");

struct fake_dev_memory{
  int magic;
  size_t size;
  memAttachKind type;
  char buf [];
};

fake_dev_memory* fake_get_mem(void * buf);



#endif
