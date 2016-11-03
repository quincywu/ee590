CXX = g++ -std=c++11 -g

SOURCES = object.cc number.cc array.cc hash.cc string.cc boolean.cc
HEADERS = json.hh object.hh number.hh array.hh hash.hh string.hh boolean.hh

OBJECTS=$(SOURCES:.cc=.o)

LIB_JSON=libjson.a

all: $(LIB_JSON)
	make -C test

$(LIB_JSON): $(OBJECTS) $(HEADERS)
	ar cr $(LIB_JSON) $(OBJECTS)

%.o: %.c $(HEADERS)
	$(CXX) -c $<

clean:
	rm -f $(OBJECTS) $(LIB_JSON)
	make -C test clean
