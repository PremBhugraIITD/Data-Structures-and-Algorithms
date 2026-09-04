#include<iostream>
#include<map>
using namespace std;
int main(){
    map <int,string> m;
    m[1]="Prem";    
    m[2]="Simran";    
    m[13]="Uday";    
    m[5]="Sumit";
    m.insert({13,"Chutki"});
    m.insert({89,"Chutki"});
    for (auto i:m){
        cout<<i.first<<":"<<i.second<<endl;
    }
    m[2]="Yati";
    cout<<m.count(13)<<endl<<m.count(90)<<endl;   
    m.erase(13);
    for (auto i:m){
        cout<<i.first<<":"<<i.second<<endl;
    }
    if(m[1]=="Prem"){
        cout<<"YES"<<endl;
    }
    if(m[7]=="Prem"){
        cout<<"YES2"<<endl;
    }
    map<int,int> n;
    cout<<n[100]<<endl;
}