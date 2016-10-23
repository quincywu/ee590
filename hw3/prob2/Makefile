CXX = g++ -std=c++11 -O3

SOURCES = complex.cc complex_operations.cc
HEADERS = complex.hh

OBJECTS=$(SOURCES:.cc=.o)

LIB_COMPLEX=libcomplex.a

all: $(LIB_COMPLEX)
	make -C test

$(LIB_COMPLEX): $(OBJECTS) $(HEADERS)
	ar cr $(LIB_COMPLEX) $(OBJECTS)

%.o: %.c $(HEADERS)
	$(CXX) -c $<

clean:
	rm -f $(OBJECTS) $(LIB_COMPLEX)
	make -C test clean
