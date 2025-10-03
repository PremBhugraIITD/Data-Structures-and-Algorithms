#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int> l;
    l.push_back(3);
    l.push_back(9);
    l.push_front(67);
    for(int i:l){
        cout<<i<<endl;
    }
    cout<<l.size()<<endl;
    l.erase(l.begin());
    cout<<l.size()<<endl;
}