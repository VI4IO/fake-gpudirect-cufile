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

typedef struct{
  int x;
} CUdevice;

typedef struct{
  int x;
} CUcontext;

struct CUdeviceptr_t{
  int x;
};

typedef struct CUdeviceptr_t* CUdeviceptr;

enum cudaMemcpyKind {
  cudaMemcpyDeviceToHost
};

CUresult cuInit(int dev);
CUresult cuDeviceGet(CUdevice * device, int dev);
CUresult cuCtxCreate(CUcontext* pctx, unsigned int  flags, CUdevice dev);
CUresult cuCtxDestroy(CUcontext ctx);
CUresult cuMemAlloc(CUdeviceptr* dptr, size_t bytesize);
CUresult cuMemFree(CUdeviceptr dptr);
CUresult cuMemsetD8(CUdeviceptr dstDevice, unsigned char  uc, size_t N);
CUresult cuGetErrorName(CUresult cu, const char ** out);


cudaError_t cudaGetLastError();
const char * cudaGetErrorString(cudaError_t err);
cudaError_t cudaMalloc(void **buf, size_t size);
cudaError_t cudaFree(void *buf);
const char * cudaGetErrorName(int err);
cudaError_t cudaMemcpy(void * dst, void *src, size_t count, enum cudaMemcpyKind k);

cudaError_t cudaSetDevice(int device);
cudaError_t cudaGetDevice(int * device);
cudaError_t cudaMemset(void* device, int val, size_t count);

#if __cplusplus
}
#endif

#endif
