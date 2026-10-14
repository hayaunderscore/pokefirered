CXX ?= g++

CXXFLAGS := -Wall -std=c++17 -O2

INCLUDES := -I tools/speciesproc

SRCS := speciesproc.cpp

HEADERS := nlohmann/json.hpp

ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

.PHONY: all clean

all: speciesproc$(EXE)
	@:

speciesproc$(EXE): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRCS) -o $@ $(LDFLAGS)

clean:
	$(RM) speciesproc speciesproc.exe
