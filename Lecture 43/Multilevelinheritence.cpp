#include<iostream>
using namespace std;
class Animal{
    public:
    int weight;
};
class Mammals: private Animal{
    protected:
    int age;
    int getweight(){
        return weight;
    }
    public:
    void setweight(int w){
        weight=w;
    }
    void setage(int age){
        this->age=age;
    }
};
class Dog: public Mammals{
    public:
    string name;
    void print(){
        cout<<"Name: "<<this->name<<", "<<"Age: "<<age<<", "<<"Weight: "<<this->getweight()<<endl;
    }
};
int main(){    
    Dog Labra;
    Labra.name = "Sheru";
    Labra.setage(3);
    Labra.setweight(10);
    Labra.print();
}