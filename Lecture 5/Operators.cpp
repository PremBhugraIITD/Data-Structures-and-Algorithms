#include<iostream>
using namespace std;
int main(){
    cout<<(2&3) <<endl;
    cout<<(2|3) <<endl;
    cout<<(~2) <<endl;
    cout<<(2^3) <<endl;
    cout<< (5<<1) <<endl;
    cout<< (3<<2) <<endl;
    cout<< (15>>1) <<endl;
    cout<< (5>>2) <<endl;
    int i = 3;
    cout<< (i++)<<endl;
    cout<< (i+=2) <<endl;
    cout<< (--i)<<endl;
    cout<< (i-=1) <<endl;
}