#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    switch (n)
    {
    case 1: cout<<"First"<<endl;
        break;
    case 2: cout<<"Second"<<endl;
    default: cout<<"Default case";
        break;
    }
}