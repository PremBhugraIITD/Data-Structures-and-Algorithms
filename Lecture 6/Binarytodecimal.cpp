#include<iostream>
#include<math.h>
using namespace std;
int main() {

    int n,digit;
    cin >> n;
    int i=0,ans=0;
    while(n!=0){
        digit=n%10;
        ans+=digit*pow(2,i);
        i+=1;
        n/=10;
    }
    cout<<ans;
}