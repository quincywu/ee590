#include "boolean.hh"

Boolean::Boolean(bool b) : boo(b) {
}

Boolean::Boolean ( const Boolean &b ){
    boo = b.boo;
}

void Boolean::set(bool b){
    boo = b;
}

std::string Boolean::stringify(){
    return (boo)?"true":"false";
}
