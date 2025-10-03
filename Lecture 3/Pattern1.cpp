#include<iostream>
using namespace std;
int main(){
    int r,c;
    cin >> r >> c;
    int i = 1;
    while (i <= r){
        int j = 1;
        while (j <= c){
            cout<< "* ";
            j = j + 1;
        }
        cout<<"\n";
        i = i + 1;
    }
}