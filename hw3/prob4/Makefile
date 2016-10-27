CXX = g++ -std=c++11 -O3

FRACTION_SOURCES = fraction.cc fraction_operations.cc
COMPLEX_SOURCES = complex.cc complex_operations.cc
DFT_SOURCES = dft.cc
HEADERS = matrix.hh matrix.impl.hh fraction.hh complex.hh dft.hh

FRACTION_OBJECTS=$(FRACTION_SOURCES:.cc=.o)
COMPLEX_OBJECTS=$(COMPLEX_SOURCES:.cc=.o)
DFT_OBJECTS=$(DFT_SOURCES:.cc=.o)

LIB_FRACTION=libfraction.a
LIB_COMPLEX=libcomplex.a
LIB_DFT=libdft.a

all: $(HEADERS) $(LIB_FRACTION) $(LIB_COMPLEX) $(LIB_DFT)
	make -C test

$(LIB_FRACTION): $(FRACTION_OBJECTS) $(HEADERS)
	ar cr $(LIB_FRACTION) $(FRACTION_OBJECTS)

$(LIB_COMPLEX): $(COMPLEX_OBJECTS) $(HEADERS)
	ar cr $(LIB_COMPLEX) $(COMPLEX_OBJECTS)

$(LIB_DFT): $(DFT_OBJECTS) $(COMPLEX_OBJECTS) $(HEADERS) 
	ar cr $(LIB_DFT) $(DFT_OBJECTS) $(COMPLEX_OBJECTS)

%.o: %.c $(HEADERS)
	$(CXX) -c $<

clean:
	rm -f $(FRACTION_OBJECTS) $(COMPLEX_OBJECTS) $(DFT_OBJECTS) $(LIB_FRACTION) $(LIB_COMPLEX) $(LIB_DFT)
	make -C test clean
