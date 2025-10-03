#include<iostream>
using namespace std;
int main(){
    int r;
    cin >> r;
    int i = 1;
    while (i <= r){
        int count  = 1;
        while (count <= i){
            cout<< char(i+64) << " ";
            count  = count + 1;
        }
        cout<<"\n";
        i = i + 1;
    }
}