#include <cuda_runtime.h>

CUresult cuInit(int dev){
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
  CUDA_SUCCESS;
}

const char * cudaGetErrorString(cudaError_t err){
  return "FAKE_NO_ERR";
}

cudaError_t cudaMalloc(void **device, size_t size){
  return cudaSuccess;
}

cudaError_t cudaFree(void *device){
  return cudaSuccess;
}

const char * cudaGetErrorName(int err){
  return cudaSuccess;
}

cudaError_t cudaMemcpy(void * dst, void *src, size_t count, enum cudaMemcpyKind k){
  return cudaSuccess;
}

cudaError_t cudaSetDevice(int device){
  return cudaSuccess;
}

cudaError_t cudaGetDevice(int *device){
  return cudaSuccess;
}

cudaError_t cudaMemset(void* device, int val, size_t count){
  return cudaSuccess;
}
