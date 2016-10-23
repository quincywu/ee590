CXX = g++ -std=c++11 -O3
LIBS = -lm -lcomplex
INCLUDE_DIRS = -I..
LIBDIRS = -L..

SOURCES = 1.cc 2.cc 3.cc 4.cc
TARGETS = $(SOURCES:%.cc=%.x)

all: $(TARGETS)

%.x: %.cc ../libcomplex.a
	$(CXX) $(INCLUDE_DIRS) $(LIBDIRS) $< $(LIBS) -o $@

test: $(TARGETS)
	./test.sh

clean:
	rm -rf $(TARGETS)
