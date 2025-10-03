#include<iostream>
using namespace std;
int main(){
    int r;
    cin  >> r;
    int i=1;
    while(i<=r){
        int j=1,k=1;
        while(j<=r-i){
            cout<<"  ";
            j = j + 1;
        }
        while(k<=i){
            cout<<"* ";
            k = k + 1;
        }
        cout <<endl;
        i=i+1;
    }
}