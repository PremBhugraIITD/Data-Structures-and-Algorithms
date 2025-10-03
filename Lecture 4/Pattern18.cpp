#include<iostream>
using namespace std;
int main(){
    int r;
    cin  >> r;
    int i=1;
    while(i<=r){
        int j=r,k=1;
        while(k<=i-1){
            cout<<"  ";
            k = k + 1;
        }
        while(j>=i){
            cout<<"* ";
            j = j - 1;
        }
        cout <<endl;
        i=i+1;
    }
}