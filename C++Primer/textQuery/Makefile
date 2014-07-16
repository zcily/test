PROGRAM := main
SOURCES := $(wildcard ./*.cpp)\
#$(wildcard ./Api/*.cpp)\
$(wildcard ./Api/porting_3_1/*.cpp)\
$(wildcard ./WebCoreSupport/156594/*.cpp)\
$(wildcard ./WebKitSupport/*.cpp)

OBJS    := $(patsubst %.cpp,%.o,$(SOURCES))

CC      := g++
CFLAGS  := -Wall -std=c++11#-DBUILD_TIME="\"`date`\"" -DDEBUG_ -ggdb

INCLUDE := -I.\
#-I./Api/ \
-I./Api/porting_3_1/ \
-I./WebCoreSupport/156594/ \
-I./WebKitSupport/

LIB     := -lpthread
.PHONY: clean

$(PROGRAM): $(OBJS)
		$(CC) -o $@ $^ $(LIB)
%.o: %.cpp
		$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDE)

clean:
		rm $(OBJS) $(PROGRAM) -f
