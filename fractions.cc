#include <iostream>
using namespace std;

class smallobj {
private:
int num; //class data
int den;

public:
    void setdata(int d) { somedata = d; }
    void showdata(){ cout << “Data is “ << somedata << endl; }
};

int main()
{
smallobj s1, s2; //define two objects of class smallobj
s1.setdata(1066); //call member function to set data
s2.setdata(1776);
s1.showdata(); //call member function to display data
s2.showdata();
return 0;
}
