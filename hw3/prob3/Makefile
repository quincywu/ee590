CXX = g++ -std=c++11 -O3

FRACTION_SOURCES = fraction.cc fraction_operations.cc
COMPLEX_SOURCES = complex.cc complex_operations.cc
HEADERS = matrix.hh matrix.impl.hh fraction.hh complex.hh

FRACTION_OBJECTS=$(FRACTION_SOURCES:.cc=.o)
COMPLEX_OBJECTS=$(COMPLEX_SOURCES:.cc=.o)

LIB_FRACTION=libfraction.a
LIB_COMPLEX=libcomplex.a

all: $(HEADERS) $(LIB_FRACTION) $(LIB_COMPLEX)
	make -C test

$(LIB_FRACTION): $(FRACTION_OBJECTS) $(HEADERS)
	ar cr $(LIB_FRACTION) $(FRACTION_OBJECTS)

$(LIB_COMPLEX): $(COMPLEX_OBJECTS) $(HEADERS)
	ar cr $(LIB_COMPLEX) $(COMPLEX_OBJECTS)

%.o: %.c $(HEADERS)
	$(CXX) -c $<

clean:
	rm -f $(FRACTION_OBJECTS) $(COMPLEX_OBJECTS) $(LIB_FRACTION) $(LIB_COMPLEX)
	make -C test clean
