REDIS_INC = $(REDIS_HOME)/deps
REDIS_LIB = $(REDIS_HOME)/deps/hiredis

CC = g++
CCFLAGS = -g -O -lhiredis
CCINC = -I$(REDIS_INC)
CCLIB = -L$(REDIS_LIB) -lhiredis
LINK.CC = $(CC) $(CCFLAGS) $(CCLIB)
COMP.CC = $(CC) $(CCINC) $(CCFLAGS) 

TARGET = ./main
all:$(TARGET)

clean:
	-@rm -f ./*.o ./main

./main: ./RedisUtil.o ./test_main.o
	$(CC) -o ./main ./RedisUtil.o ./test_main.o $(CCLIB)

./RedisUtil.o:
	$(COMP.CC) -o ./RedisUtil.o -c ./RedisUtil.cpp 

./test_main.o:
	$(COMP.CC) -o ./test_main.o -c ./test_main.cpp 
