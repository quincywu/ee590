#include "string.hh"

String::String(std::string s){
    str = s;
}

String::String ( const String &s ){
    str = s.str;
}

void String::set(std::string s){
    str = s;
}

std::string String::stringify(){

    return "\"" + str + "\"";

}
