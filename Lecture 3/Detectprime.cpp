#include<iostream>
using namespace std;
int main(){
    cout<< "Enter number\n";
    int n;
    cin >> n;
    int i = 2;
    int count = 0;
    while (i<n){
        if (n%i == 0){
            count = count + 1;
        }
        i = i + 1;
    }
    if (count  == 0){
        cout<<"Prime number";
    }
    else{
        cout<<"Not prime";
    }
}