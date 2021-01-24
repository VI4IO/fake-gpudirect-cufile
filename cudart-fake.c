#include "fake-cufile-internal.h"

static int device = 0;

static fake_dev_memory * fake_malloc(size_t size, memAttachKind type){
  fake_dev_memory * mem;
  posix_memalign((void**) & mem, 4096, sizeof(fake_dev_memory) + size);
  mem->magic = FMAGIC;
  mem->size = size;
  mem->type = type;
  return mem;
}

fake_dev_memory * fake_get_mem(void * buf){
    fake_dev_memory * mem = (fake_dev_memory*) ((char*)buf - sizeof(fake_dev_memory));
    if(mem->magic != FMAGIC){
      return NULL;
    }
    return mem;
}

CUresult cuInit(int dev){
  device = dev;
  return CUDA_SUCCESS;
}

CUresult cuDeviceGet(CUdevice * device, int dev){
  assert(device);
  *device = (CUdevice){ .device = dev };
  return CUDA_SUCCESS;
}

CUresult cuCtxCreate(CUcontext* pctx, unsigned int flags, CUdevice dev){
  assert(pctx);
  pctx->flags = flags;
  pctx->device = dev;

  return CUDA_SUCCESS;
}

CUresult cuCtxDestroy(CUcontext ctx){
  return CUDA_SUCCESS;
}

CUresult cuMemAlloc(CUdeviceptr* dptr, size_t size){
  assert(dptr);
  fake_dev_memory * mem = fake_malloc(size, cudaMemAttachDevice);
  *dptr = mem;
  return CUDA_SUCCESS;
}

CUresult cuMemFree(CUdeviceptr dptr){
  assert(dptr);
  if(dptr->magic != FMAGIC){
    return CUDA_ERROR;
  }
  free(dptr);
  return CUDA_SUCCESS;
}

CUresult cuMemsetD8(CUdeviceptr dptr, unsigned char val, size_t count){
  if(dptr->magic != FMAGIC){
    return CUDA_ERROR;
  }
  assert(count <= dptr->size);
  memset(dptr->buf, val, count);
  return CUDA_SUCCESS;
}

CUresult cuGetErrorName(CUresult cu, const char ** out){
  *out = "FAKE CU ERROR";
  return CUDA_SUCCESS;
}


cudaError_t cudaGetLastError(){
  return CUDA_SUCCESS;
}

const char * cudaGetErrorString(cudaError_t err){
  return "FAKE_NO_ERR";
}

cudaError_t cudaMalloc(void **buf, size_t size){
  fake_dev_memory * mem = fake_malloc(size, cudaMemAttachDevice);
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
  if(k == cudaMemcpyDeviceToHost){
    fake_dev_memory * mem = fake_get_mem(src);
    if(! mem){
      return cudaError;
    }
    assert(count <= mem->size);
  }else if(k == cudaMemcpyHostToDevice){
    fake_dev_memory * mem = fake_get_mem(dst);
    if(! mem){
      return cudaError;
    }
    assert(count <= mem->size);
  }
  memcpy(dst, src, count);
  return cudaSuccess;
}

cudaError_t cudaMemset(void* buf, int val, size_t count){
  fake_dev_memory * mem = fake_get_mem(buf);
  if(! mem){
    return cudaError;
  }
  assert(count <= mem->size);
  memset(mem->buf, val, count);
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

cudaError_t cudaMallocManaged(void **buf, size_t size, memAttachKind type){
  fake_dev_memory * mem = fake_malloc(size, type);
  *buf = (void*) mem->buf;
  return cudaSuccess;
}

cudaError_t cudaFreeHost(void *buf){
  fake_dev_memory * mem = fake_get_mem(buf);
  if(! mem){
    return CUDA_ERROR;
  }
  return cudaFree(buf);
}

cudaError_t cudaMallocHost(void **buf, size_t size){
  fake_dev_memory * mem = fake_malloc(size, cudaMemAttachHost);
  *buf = (void*) mem->buf;
  return cudaSuccess;
}
