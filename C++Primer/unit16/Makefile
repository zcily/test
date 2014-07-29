# The executable file name.
# It must be specified.
# PROGRAM   := a.out    # the executable name
PROGRAM   := a.out

# The directories in which source files reside.
# At least one path should be specified.
# SRCDIRS   := .        # current directory
SRCDIRS   := .
SRCDIRS   += ./test

# add the include file
INCLUDE := -I.\
-I./test/
#-I./Api/ \
-I./Api/porting_3_1/ \
-I./WebCoreSupport/156594/ \
-I./WebKitSupport/

# The source file types (headers excluded).
# At least one type should be specified.
# The valid suffixes are among of .c, .C, .cc, .cpp, .CPP, .c++, .cp, or .cxx.
# SRCEXTS   := .c      # C program
# SRCEXTS   := .cpp    # C++ program
# SRCEXTS   := .c .cpp # C/C++ program
SRCEXTS   := .c .cpp

# The compiling flags used only for C.
# If it is a C++ program, no need to set these flags.
# If it is a C and C++ merging program, set these flags for the C parts.
CFLAGS    := -g 
CFLAGS    += -Wall

# The compiling flags used only for C++.
# If it is a C program, no need to set these flags.
# If it is a C and C++ merging program, set these flags for the C++ parts.
CXXFLAGS  := -g
CXXFLAGS  += --std=c++11

# The library and the link options ( C and C++ common).
LDFLAGS   :=
LDFLAGS   +=

## Implict Section: change the following only when necessary.
##=============================================================================
# The C program compiler. Uncomment it to specify yours explicitly.
CC      = gcc

# The C++ program compiler. Uncomment it to specify yours explicitly.
CXX     = g++

# Uncomment the 2 lines to compile C programs as C++ ones.
CC      = $(CXX)
CFLAGS  = $(CXXFLAGS) -o $@

# The command used to delete file.
RM        = rm -f

# the -lxxxxx you want to add
LIB     := -lpthread


## Stable Section: usually no need to be changed. But you can add more.
##=============================================================================
SHELL   = /bin/sh
SOURCES = $(foreach d,$(SRCDIRS),$(wildcard $(addprefix $(d)/*,$(SRCEXTS))))
OBJS    = $(foreach x,$(SRCEXTS), \
      $(patsubst %$(x),%.o,$(filter %$(x),$(SOURCES))))
DEPS    = $(patsubst %.o,%.d,$(OBJS))

.PHONY : all objs clean cleanall rebuild

all : $(PROGRAM) clean

# Rules for producing the objects.
#---------------------------------------------------
objs : $(OBJS)

%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $< $(INCLUDE)

%.o : %.C
	$(CXX) -c $(CXXFLAGS) -o $@ $< $(INCLUDE)

%.o : %.cc
	$(CXX) -c  $(CXXFLAGS) -o $@ $< $(INCLUDE)

%.o : %.cpp
	$(CXX) -c  $(CXXFLAGS) -o $@ $< $(INCLUDE)

%.o : %.CPP
	$(CXX) -c  $(CXXFLAGS) -o $@ $< $(INCLUDE)

%.o : %.c++
	$(CXX -c  $(CXXFLAGS) -o $@ $< $(INCLUDE)

%.o : %.cp
	$(CXX) -c  $(CXXFLAGS) -o $@ $< $(INCLUDE)

%.o : %.cxx
	$(CXX) -c  $(CXXFLAGS) -o $@ $< $(INCLUDE)

# Rules for producing the executable.
#----------------------------------------------
$(PROGRAM) : $(OBJS)
ifeq ($(strip $(SRCEXTS)), .c)  # C file
	$(CC) -o $(PROGRAM) $(OBJS) $(LDFLAGS) $(LIB) $(INCLUDE)
else                            # C++ file
	$(CXX) -o $(PROGRAM) $(OBJS) $(LDFLAGS) $(LIB) $(INCLUDE)
endif

-include $(DEPS)

rebuild: clean all

clean :
	@$(RM) $(OBJS)

cleanall: clean
	@$(RM) $(PROGRAM)

### End of the Makefile ##  Suggestions are welcome  ## All rights reserved ###
###############################################################################
