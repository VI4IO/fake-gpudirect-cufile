# Fake gpuDirect/cuFile Library (FakeGD)

This library provides pseudo prototypes for NVIDIA cufile.h and cuda.h to simplify porting of applications to gpuDirect.
The goal is to provide a drop-in memory replacement for cufile.h.
This is motivated by the fact that development for gpuDirect turned out to be tricky on the system(s) I had at hand.

This project is not related whatsoever with NVIDIA.
Any information about prototypes are publicly available / provided by NVIDIA.

## Build instructions

You need to obtain the cufile.h header from NVIDIA and place it into the include directory.
The required CUDA functions are implemented as fake.

## Status

The gds/samples*.cc 1-14 from NVIDIA are building with the library and can be executed.
However, note that the functionality of the library is not complete.

In the Makefile of the gds examples you need to change:
CUDA_PATH := PATH TO fake-gpudirect-cufile/
CUFILE_PATH ?= $(CUDA_PATH)/include

CUFILE_LIB  := -L $(CUFILE_PATH) -lcufile  -Wl,-rpath=$(CUDA_PATH)/lib64/

