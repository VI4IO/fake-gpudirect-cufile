#ifndef CUDA_RT_FAKE_H
#define CUDA_RT_FAKE_H

/*
 Use only public information to fake the CUDA library
 */

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif

typedef enum{
  cudaSuccess = 0,
  cudaError = 1,
} cudaError_t;

typedef enum{
  CUDA_SUCCESS,
  CUDA_ERROR,
  CUDA_ERROR_INVALID_VALUE
} CUresult;

typedef struct fake_CUdevice   fake_CUdevice;
typedef struct fake_CUcontext  fake_CUcontext;
typedef struct fake_dev_memory fake_dev_memory;

struct fake_CUdevice{
  int device;
};

struct fake_CUcontext{
  int flags;
  fake_CUdevice device;
};

typedef struct fake_CUdevice CUdevice;
typedef struct fake_CUcontext CUcontext;
typedef struct fake_dev_memory* CUdeviceptr;

typedef enum cudaMemcpyKind {
  cudaMemcpyDeviceToHost = 1,
  cudaMemcpyHostToDevice = 2
} cudaMemcpyKind;

typedef enum memAttachKind {
  cudaMemAttachGlobal = 1,
  cudaMemAttachHost = 2,
  cudaMemAttachDevice = 4,
} memAttachKind;

CUresult cuInit(int dev);
CUresult cuDeviceGet(CUdevice * device, int dev);
CUresult cuCtxCreate(CUcontext* pctx, unsigned int  flags, CUdevice dev);
CUresult cuCtxDestroy(CUcontext ctx);
CUresult cuMemAlloc(CUdeviceptr* dptr, size_t bytesize);
CUresult cuMemFree(CUdeviceptr dptr);
CUresult cuMemsetD8(CUdeviceptr dstDevice, unsigned char val, size_t count);
CUresult cuGetErrorName(CUresult cu, const char ** out);


cudaError_t cudaGetLastError();
const char * cudaGetErrorString(cudaError_t err);
cudaError_t cudaMalloc(void **buf, size_t size);
cudaError_t cudaFree(void *buf);
const char * cudaGetErrorName(int err);
cudaError_t cudaMemcpy(void * dst, void *src, size_t count, cudaMemcpyKind k);

cudaError_t cudaSetDevice(int device);
cudaError_t cudaGetDevice(int * device);
cudaError_t cudaMemset(void* device, int val, size_t count);


cudaError_t cudaMallocManaged(void **buf, size_t size, memAttachKind);
cudaError_t cudaFreeHost(void *buf);
cudaError_t cudaMallocHost(void **buf, size_t size);


#if __cplusplus
}
#endif

#endif
