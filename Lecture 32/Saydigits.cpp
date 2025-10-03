#include<iostream>
using namespace std;
void saydigits(int n,string arr[])
{   
    if(n==0){
        return ;
    }
    int digit = n%10;
    saydigits(n/10,arr);
    cout<<arr[digit]<<" ";
}
int main(){
    string digits[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int n;
    cin>>n;
    saydigits(n,digits);
}