#include<iostream>
using namespace std;
int main(){
    char op;
    int a,b;
    cout<<"Enter the first number"<<endl;
    cin>>a;
    cout<<"Enter the second number"<<endl;
    cin>>b;
    cout<<"Enter the operation"<<endl;
    cin>>op;
    switch(op){
        case '+': cout<<(a+b);
        break;
        case '-': cout<<(a-b);
        break;
        case '*': cout<<(a*b);
        break;
        case '/': cout<<(a/b);
        break;
        default: cout<<"Input invalid";
    }
}