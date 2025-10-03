#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int> s;
    s.insert(5);
    s.insert(1);
    s.insert(7);
    s.insert(90);
    s.insert(3);
    s.insert(1);
    cout<<s.size()<<endl;
    for(auto i:s){
        cout<<i<<endl;
    }
    s.erase(s.begin());
    for(auto i:s){
        cout<<i<<endl;
    }
    cout<<s.count(7)<<endl<<s.count(1)<<endl;
}