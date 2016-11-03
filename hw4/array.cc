#include "array.hh"
#include "null.hh"

Array::Array() {
  max = 10;
  values = new Object *[max];
  for ( int i=0; i < max; i++ ) {
    values[i] = NULL;
  }
}

Array::Array ( const Array &array ) {

  max = array.max;
  values = new Object *[max];
  for ( int i=0; i < max; i++ ) {
    if(array.values[i] != NULL)
        values[i] = array.values[i]->clone();
    else
        values[i] = NULL;
  }

}

// added destructor
Array::~Array () {
  for(int i = 0; i < max; i++)
    delete values[i];
  delete[] values;

}

int Array::length(){
    int i = 0;
    int length = 0;

    for(; i < max; i++){
        if(values[i] != NULL){
            length = i + 1;
        }
    }

    return length;
}

void Array::set(int index, Object &object) {
  while ( index >= max ){
    // increase max and copy to an temp array
    int temp_max = 2 * max;
    Object **temp_values = new Object *[temp_max];

    for ( int i=0; i < temp_max; i++ ) {
      if( i < max && values[i] ){
          temp_values[i] = values[i]->clone();
      }else{
          temp_values[i] = NULL;
      }
    }

    //delete origininal
    for(int i = 0; i < max; i++)
      delete values[i];
    delete[] values;

    max = temp_max;
    values = temp_values;

  }

  if ( values[index] != NULL ) {
    delete values[index];
  }
  values[index] = object.clone();
}

Object* Array::get(int index) {
  if ( 0 <= index && index < max && values[index] != NULL ) {
    return values[index];
  } else {
    throw object_exception ("Array out of bounds");
  }
}

std::string Array::stringify() {

  std::string s = "[";

  int m = -1;

  for ( int i=0; i<max; i++ ) {
    if ( values[i] != NULL ) {
      m = i;
    }
  }

  for ( int i=0; i<=m; i++ ) {
    if ( values[i] != NULL ) {
      s += values[i]->stringify();
    } else {
      s += "null";
    }
    if ( i < m ) {
      s += ",";
    }
  }

  s += "]";

  return s;

}
