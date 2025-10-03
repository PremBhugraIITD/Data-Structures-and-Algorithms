#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack <string> s;
    s.push("Prem");
    s.push("Simran");
    s.push("Mayur");
    cout<<s.size()<<endl<<s.top()<<endl;
    s.pop();
    cout<<s.size()<<endl<<s.top()<<endl;
}