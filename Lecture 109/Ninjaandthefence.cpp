#include<iostream>
using namespace std;
//Without DP
int numberOfWays(int n, int k) {
    if(n==1){
        return k;
    }
    else if(n==2){
        return k*k;
    }
    return (k-1)*(numberOfWays(n-1,k) + numberOfWays(n-2,k));
}
int main(){
    cout<<numberOfWays(3,2)<<"    "<<numberOfWays(2,4)<<"    "<<numberOfWays(4,2)<<endl;
}