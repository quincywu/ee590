CXX = g++ -std=c++11
LIBS = -lm -lfraction -lcomplex -ldft
INCLUDE_DIRS = -I..
LIBDIRS = -L..

SOURCES = 1.cc
TARGETS = $(SOURCES:%.cc=%.x)

all: $(TARGETS)

%.x: %.cc ../*.hh ../*.a
	$(CXX) $(INCLUDE_DIRS) $(LIBDIRS) $< $(LIBS) -o $@

test: $(TARGETS)
	./test.sh

clean:
	rm -rf $(TARGETS)
