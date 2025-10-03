#include<iostream>
#include<stack>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    stack<char> w;
    for(int i=0;i<s.size();i++){
        w.push(s[i]);
    }
    for(int j=0;j<s.size();j++){
        s[j]=w.top();
        w.pop();
    }
    cout<<s<<endl;
}
//TC=O(n)
//SC=O(n)