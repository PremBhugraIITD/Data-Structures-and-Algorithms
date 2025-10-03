#include<iostream>
using namespace std;
int main(){
    int r;
    cin >> r;
    int i = 1,j = 1;
    while (i <= r){
        int count  = 1;
        while (count <= i){
            cout<< j << " ";
            j = j + 1;
            count  = count + 1;
        }
        cout<<"\n";
        i = i + 1;
    }
}