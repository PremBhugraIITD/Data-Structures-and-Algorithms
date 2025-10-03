#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<< "Enter the value of a and b" <<endl;
    cin >> a >> b;
    if (a>b){
    cout<<"a is greater" <<endl;
    }
    else if (a == b){
    cout<<"Both are equal" <<endl;
    }
    else{
    cout<<"b is greater" <<endl;
    }
}