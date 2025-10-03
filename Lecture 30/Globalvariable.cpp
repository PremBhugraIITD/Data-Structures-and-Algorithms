#include<iostream>
using namespace std;
int score = 12;      //score is a Global Variable
void func(){
    score+=1;
    cout<<score<<endl;
}
void update(int &b){    
    b+=1;
    cout<<b<<endl;
}
int main(){
    int i=5;
    score+=1;
    {
        int i=2;      //i is a Local Variable for this block
        cout<<i<<endl;
    }
    cout<<score<<endl;
    func();
    cout<<score<<endl;
    int a=10;
    update(a);         //a is being shared between main and update functions
    cout<<a<<endl;
}