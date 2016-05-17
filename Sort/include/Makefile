.PHONY:all
all:libfunc.a

libfunc.a:func.h
	g++ -c $^
	ar -crv libfunc.a func.o 

.PHONY:clean
clean:
	rm -rf  libfunc.a func.o
