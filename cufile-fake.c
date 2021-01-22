#include <cuda_runtime.h>

typedef struct {
  int x;
} CUfileError_t;

typedef struct {
  int x;
} CUfileDrvProps_t;

typedef struct{
  int x;
} CUfileHandle_t;

typedef struct{
  int x;
} CUfileDescr_t;

#define CUFILE_SUCCESS (CUfileError_t){0};

CUfileError_t cuFileHandleRegister(CUfileHandle_t *fh, CUfileDescr_t *descr){
  return CUFILE_SUCCESS;
}

void cuFileHandleDeregister(CUfileHandle_t fh){
}

CUfileError_t cuFileBufRegister(const void *devPtr_base, size_t length, int flags){
  return CUFILE_SUCCESS;
}

CUfileError_t cuFileBufDeregister(const void *devPtr_base){
  return CUFILE_SUCCESS;
}

ssize_t cuFileRead(CUfileHandle_t fh, void *devPtr_base, size_t size, off_t file_offset, off_t devPtr_offset){
  return size;
}

ssize_t cuFileWrite(CUfileHandle_t fh, const void *devPtr_base, size_t size, off_t file_offset, off_t devPtr_offset){
  return size;
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

CUfileError_t cuFileDriverSetPollMode(bool poll, size_t poll_threshold_size){
  return CUFILE_SUCCESS;
}

CUfileError_t cuFileDriverSetMaxDirectIOSize(size_t max_direct_io_size){
  return CUFILE_SUCCESS;
}

CUfileError_t cuFileDriverSetMaxCacheSize(size_t max_cache_size){
  return CUFILE_SUCCESS;
}

CUfileError_t cuFileDriverSetMaxPinnedMemSize(size_t max_pinned_size){
  return CUFILE_SUCCESS;
}
