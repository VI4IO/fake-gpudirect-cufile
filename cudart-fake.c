#include "fake-cufile-internal.h"

static int device = 0;

CUresult cuInit(int dev){
  device = dev;
  return CUDA_SUCCESS;
}

CUresult cuDeviceGet(CUdevice * device, int dev){
  return CUDA_SUCCESS;
}

CUresult cuCtxCreate(CUcontext* pctx, unsigned int  flags, CUdevice dev){
  return CUDA_SUCCESS;
}

CUresult cuCtxDestroy(CUcontext ctx){
  return CUDA_SUCCESS;
}

CUresult cuMemAlloc(CUdeviceptr* dptr, size_t bytesize){

  return CUDA_SUCCESS;
}

CUresult cuMemFree(CUdeviceptr dptr){
  return CUDA_SUCCESS;
}

CUresult cuMemsetD8(CUdeviceptr dstDevice, unsigned char  uc, size_t N){
  return CUDA_SUCCESS;
}

CUresult cuGetErrorName(CUresult cu, const char ** out){
  return CUDA_SUCCESS;
}

cudaError_t cudaGetLastError(){
  return CUDA_SUCCESS;
}

const char * cudaGetErrorString(cudaError_t err){
  return "FAKE_NO_ERR";
}

cudaError_t cudaMalloc(void **buf, size_t size){
  fake_dev_memory * mem = malloc(sizeof(fake_dev_memory) + size);
  mem->magic = 4711;
  mem->size = size;
  *buf = (void*) mem->buf;
  return cudaSuccess;
}

cudaError_t cudaFree(void *buf){
  fake_dev_memory * mem = fake_get_mem(buf);
  if(! mem){
    return cudaError;
  }
  return cudaSuccess;
}

const char * cudaGetErrorName(int err){
  return "FAKE NO ERR";
}

cudaError_t cudaMemcpy(void * dst, void *src, size_t count, enum cudaMemcpyKind k){
  memcpy(dst, src, count);
  return cudaSuccess;
}

cudaError_t cudaMemset(void* buf, int val, size_t count){
  fake_dev_memory * mem = fake_get_mem(buf);
  if(! mem){
    return cudaError;
  }  
  memset(buf, val, count);
  return cudaSuccess;
}

cudaError_t cudaSetDevice(int dev){
  device = dev;
  return cudaSuccess;
}

cudaError_t cudaGetDevice(int *dev){
  *dev = device;
  return cudaSuccess;
}

fake_dev_memory * fake_get_mem(void * buf){
    fake_dev_memory * mem = (fake_dev_memory*) ((char*)buf - sizeof(fake_dev_memory));
    if(mem->magic != 4711){
      return NULL;
    }
    return mem;
}
