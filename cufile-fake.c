#include <cuda_runtime.h>
#include <cufile.h>
#include <unistd.h>
#include "fake-cufile-internal.h"

#define CUFILE_SUCCESS (CUfileError_t){0};

CUfileError_t cuFileHandleRegister(CUfileHandle_t *fh, CUfileDescr_t *descr){
  CUfileDescr_t * tmp = malloc(sizeof(CUfileDescr_t));
  *tmp = *descr;
  *fh = tmp;
  return CUFILE_SUCCESS;
}

void cuFileHandleDeregister(CUfileHandle_t fh){
  free(fh);
}

CUfileError_t cuFileBufRegister(const void *ptr, size_t length, int flags){
  return CUFILE_SUCCESS;
}

CUfileError_t cuFileBufDeregister(const void *ptr){
  return CUFILE_SUCCESS;
}

ssize_t cuFileRead(CUfileHandle_t fh, void *ptr, size_t size, off_t off, off_t devOffset){
  CUfileDescr_t * d = (CUfileDescr_t*) fh;
  assert(d->type == CU_FILE_HANDLE_TYPE_OPAQUE_FD);
  fake_dev_memory * mem = fake_get_mem(ptr);
  if(! mem){
    return -1;
  }
  ssize_t ret = pread(d->handle.fd, mem->buf + devOffset, size, off);
  return ret;
}

ssize_t cuFileWrite(CUfileHandle_t fh, const void *ptr, size_t size, off_t off, off_t devOffset){
  CUfileDescr_t * d = (CUfileDescr_t*) fh;
  assert(d->type == CU_FILE_HANDLE_TYPE_OPAQUE_FD);
  fake_dev_memory * mem = fake_get_mem(ptr);
  if(! mem){
    return -1;
  }
  ssize_t ret = pwrite(d->handle.fd, mem->buf + devOffset, size, off);
  return ret;
}

CUfileError_t cuFileDriverOpen(void){
  return CUFILE_SUCCESS;
}

CUfileError_t cuFileDriverClose(void){
  return CUFILE_SUCCESS;
}

CUfileError_t cuFileDriverGetProperties(CUfileDrvProps_t *props){
  return CUFILE_SUCCESS;
}

CUfileError_t cuFileDriverSetPollMode(bool poll, size_t thress){
  return CUFILE_SUCCESS;
}

CUfileError_t cuFileDriverSetMaxDirectIOSize(size_t max_size){
  return CUFILE_SUCCESS;
}

CUfileError_t cuFileDriverSetMaxCacheSize(size_t max_cache){
  return CUFILE_SUCCESS;
}

CUfileError_t cuFileDriverSetMaxPinnedMemSize(size_t max_pinned){
  return CUFILE_SUCCESS;
}
