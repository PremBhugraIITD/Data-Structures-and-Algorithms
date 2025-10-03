#include<iostream>
using namespace std;
int main(){
    int r,c;
    cin >> r >> c;
    int i = 1;
    int j = 1;
    while (i <= r){
        int count = 1;
        while (count <= c){
            cout<< char(j + 64) << " ";
            j = j + 1;
            count  = count + 1;
        }
        cout<<"\n";
        i = i + 1;
    }
}