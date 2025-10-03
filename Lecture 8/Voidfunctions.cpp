#include<iostream>
using namespace std;
void counting(int n){
    for (int i = 1; i <= n; i++)
    {
        cout<<i<<"\t";
    }
    return ;
}
int main(){
    int a;
    cin>>a;
    counting(a);
}