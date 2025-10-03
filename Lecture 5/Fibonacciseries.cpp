#include<iostream>
using namespace std;
int main(){
    int n,a=0,b=1,temp;
    cin>>n;
    for (int i = 1; i < n; i++)
    {
        temp=a;
        a=b;
        b+=temp;
    }
    cout<<b;
}