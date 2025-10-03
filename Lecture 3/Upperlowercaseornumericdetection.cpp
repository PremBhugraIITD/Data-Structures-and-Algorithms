#include<iostream>
using namespace std;
int main(){
    cout<< "Enter" <<endl;
    char ch;
    cin>>ch;
    if ((int(ch) >= 48) && (int(ch) <= 57)){
    cout << "Numeric" <<endl;}
    else if ((int(ch) >= 65) && (int(ch) <= 90)){
    cout << "Uppercase Alphabet" <<endl;
    }
    else if ((int(ch) >= 97) && (int(ch) <= 122)){
    cout << "Lowercase Alphabet" <<endl;
    }
}