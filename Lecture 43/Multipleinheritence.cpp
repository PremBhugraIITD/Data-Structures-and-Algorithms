#include<iostream>
using namespace std;
class Terrestial{
    public:
    int legs;
};
class Aerial{
    public:
    int wings;
};
class Griffin: public Terrestial, private Aerial{
    public:
    void print(){
        cout<<"Legs: "<<legs<<", "<<"Wings: "<<wings<<endl;
    }
};
int main(){
    Griffin Garun;
    Garun.legs = 2;
    Garun.print();
}