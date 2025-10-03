#include<iostream>
using namespace std;
int factorial(int n){
    if(n==0){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}
int power_of_two(int n){
    if(n==0){
        return 1;
    }
    else{
        return 2*power_of_two(n-1);
    }
}
int main(){
    int n;
    cin>>n;
    cout<<factorial(n)<<endl;
    cout<<power_of_two(n)<<endl;
}