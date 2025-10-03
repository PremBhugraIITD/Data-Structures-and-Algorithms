#include<iostream>
using namespace std;
int main(){
    cout << "Hello World!\n";     
    /*This is a 
    multiline comment*/
    //This is a single line comment
    cout << "Prem" << endl;
    bool bl = true;
    cout << bl << endl;
    int a = 3; float c = 9.6; double d = 9.567; char h = 'y';
    cout << a << endl;
    cout << c << d << h << endl;
    cout << sizeof(d) <<endl;
    int z = 'z'; char y = 98;
    cout << z << y << endl;
    unsigned x = 123, m = -123;
    cout << x << endl << m << endl;
    int n = 2/5; float p = 2.0/5; double q = 2.0/5.0;
    cout << n << endl << p << endl << q << endl;
    int r = 2, s = 8;
    cout << (r == s) << bool(r <= s);
    int i = 1;
    cout << !i<<endl;
    string prem = {"Hello"};
    cout<<prem[1]<<endl<<prem;
}