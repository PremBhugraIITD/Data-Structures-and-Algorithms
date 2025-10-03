#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int count=0;
    for(int i=0;i<s.length();i++){
        if(s[i]!=s[s.length()-i-1]){
            cout<<"It is not a palindrome";
            count++;
            break;
        }
    }
    if(count==0){
        cout<<"It is a palindrome";
    }
}