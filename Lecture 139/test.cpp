#include<iostream>
using namespace std;
int main(){
    string s = "a";
    string t = "hello world";
    int i = 0;
    while(i<t.length()){
        while(s[i]!=t[i]){
            cout<<s<<endl;
            s[i]++;
        }
        i++;
        s+='a';
        if(i==5){
            s[s.length()-1] = ' ';
        }
    }
    cout<<"hello world"<<endl;
}