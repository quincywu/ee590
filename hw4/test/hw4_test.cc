#include <iostream>
#include "json.hh"

int main ( int argc, char * argv[] ) {
    //test json class
    /*
    {
        "ee590": "is fun",
        "C++": [ "is", { "adjective": "arcane" } ],
        "Ruby": { "used by": "hipsters", "poetic": true },
        "Java": [ "JavaHomeworkAssignmentTestCodeLibraryAssessorFuncTest", 0, null, "zero", {} ],
        "Javascript": "Resistance is futile"
    }
    */

    Hash h;
    String s ("is fun");

    h.set ( "ee590", s);

    Array array;
    s.set("is");
    array.set(0,s);
    Hash second_hash;
    String str ("arcane");
    second_hash.set ( "adjective", str);
    array.set(1,second_hash);
    h.set ( "C++", array);

    Hash third_hash;
    s.set("hipsters");
    Boolean b(true);
    third_hash.set("used by", s);
    third_hash.set("poetic", b);
    h.set("Ruby", third_hash);

    s.set("JavaHomeworkAssignmentTestCodeLibraryAssessorFuncTest");
    Number n (0);
    str.set("zero");
    Hash fourth_hash;
    array.set(0, s);
    array.set(1, n);
    array.set(3, str);
    array.set(4, fourth_hash);
    h.set("Java", array);

    s.set("Resistance is futile");
    h.set("Javascript", s);

    std::cout << h.stringify() << std::endl;
    std::cout << h.get("Java")->stringify() << std::endl;
    std::cout << h.get("Java")->get(1)->stringify()  << std::endl;
    std::cout << h.get("Java")->get(4)->stringify()  << std::endl;

    std::cout << h.get("ee590")->stringify() << std::endl;

    std::cout << h.get("C++")->stringify() << std::endl;
    std::cout << h.get("C++")->get(1)->get("adjective")->stringify() << std::endl;

  return 0;

}
