#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<string> q;
    q.push("Prem");
    q.push("Simran");
    q.push("Uday");
    cout<<q.size()<<endl<<q.front()<<endl<<q.back()<<endl;
    q.pop();
    cout<<q.size()<<endl<<q.front()<<endl<<q.back()<<endl;
}