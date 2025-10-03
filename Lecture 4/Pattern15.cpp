#include<iostream>
using namespace std;
int main(){
    int r;
    cin  >> r;
    int i = 1;
    while (i<=r){
        int j = r - i + 1;
        int count = 1;
        while (count<=i){
            cout << char(j+64) << " ";
            j = j + 1;
            count  = count + 1;
        } 
        cout << "\n";
        i = i + 1;
    }
}