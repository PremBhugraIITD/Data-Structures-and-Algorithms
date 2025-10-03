#include<iostream>
#include<string>
using namespace std;
int main(){
    string name2;
    cout<<"Input name2"<<endl;
    getline(cin,name2);
    cout<<"Your full name is "<<name2<<endl;
    char name[5];
    cout<<"Enter your name"<<endl;
    cin >> name;
    name[2] = '\0';
    cout<<"Your name is "<<name<<endl;
}