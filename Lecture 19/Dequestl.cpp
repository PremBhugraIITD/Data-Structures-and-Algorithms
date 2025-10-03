#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> d;
    cout<<d.size()<<endl<<d.max_size()<<endl;
    d.push_back(43);
    d.push_front(32);
    cout<<d.size()<<endl;
    for (int i=0;i<d.size();i++){
        cout<<d.at(i)<<endl;
    }
    d.pop_back();
    d.pop_front();
    cout<<d.size()<<endl<<d.empty()<<endl;
    deque<int> e;
    e.push_back(45);
    e.push_back(32);
    e.push_back(21);e.push_back(21);e.push_back(1);e.push_back(45);e.push_back(78);
    for (int i=0;i<e.size();i++){
        cout<<e.at(i)<<endl;
    }
    e.erase(e.begin(),e.begin()+4);
    for (int i=0;i<e.size();i++){
        cout<<e.at(i)<<endl;
    }
}