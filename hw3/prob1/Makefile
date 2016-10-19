CXX = g++ -std=c++11 -O3

SOURCES = fraction.cc fraction_operations.cc
HEADERS = fraction.hh

OBJECTS=$(SOURCES:.cc=.o)

LIB_FRACTION=libfraction.a

all: $(LIB_FRACTION)
	make -C test

$(LIB_FRACTION): $(OBJECTS) $(HEADERS)
	ar cr $(LIB_FRACTION) $(OBJECTS)

%.o: %.c $(HEADERS)
	$(CXX) -c $<

clean:
	rm -f $(OBJECTS) $(LIB_FRACTION)
	make -C test clean
