#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    int i=0;
    long long int ans = 0;
    cin >> n;
    while(n){
        int bit=n&1;
        ans+=bit*pow(10,i++);
        n=n>>1;
    }
    cout << ans<<endl; // It will not give the correct answer here but on an online IDE.
}