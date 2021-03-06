CFLAGS=-I./include -I./cuda/include -g3

all: lib64/libcuda.so lib64/libcufile.so lib64/libcufile.a lib64/libcudart_static.a

.PHONY: lib64

lib64:
	mkdir lib64

lib64/libcuda.so: cuda-fake.c
	gcc $(CFLAGS) -c -fpic $<
	gcc -shared -o lib64/libcuda.so cuda-fake.o $(LDFLAGS)

lib64/libcufile.so: cufile-fake.c
	gcc $(CFLAGS) -c -fpic $<
	gcc -shared -o lib64/libcufile.so cufile-fake.o $(LDFLAGS)

lib64/libcufile.a: cufile-fake.c
	gcc $(CFLAGS) -c -fpic $< -o lib64/libcufile_static.o $(LDFLAGS)
	ar rcs lib64/libcufile.a lib64/libcufile_static.o


lib64/libcudart_static.a: cudart-fake.c
	gcc $(CFLAGS) -c $<
	ar rcs lib64/libcudart_static.a cudart-fake.o

.PHONY: clean
clean:
	rm lib64/*.a lib64/*.so *.o
