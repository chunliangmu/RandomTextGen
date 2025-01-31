# Makefile for ???
#
# By ???
#
# See also:
#	https://www.gnu.org/software/make/manual/html_node/index.html


# Variables

# CC=gcc
CXX := g++
CPPFLAGS :=
CXXFLAGS := -std=c++17
LDFLAGS  :=
LDLIBS   :=

RM := rm -f
OBJDIR := obj/
EXEDIR := bin/

EXE  := $(EXEDIR)RandomTextGen
SRCS := RandomTextGen.cpp
OBJS := $(addprefix $(OBJDIR),$(notdir $(SRCS:.cpp=.o)))


# Dependencies

.PHONY: all dirs clean

all: dirs $(OBJS) $(EXE)

dirs : $(EXEDIR) $(OBJDIR)

# $(OBJS): | $(OBJDIR)

$(EXEDIR):
	mkdir -p $(EXEDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)


# Create objects from source files

$(OBJDIR)%.o : %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# Link objects into executable

$(EXE): $(OBJS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS)

# Main

clean:
	$(RM) $(OBJ_DIR)*
	$(RM) $(EXE)
