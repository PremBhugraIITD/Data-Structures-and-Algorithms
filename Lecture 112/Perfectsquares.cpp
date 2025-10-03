#include<iostream>
#include<limits.h>
using namespace std;
//Without DP
int numSquares(int n) {
    if(n<=0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    int mini = INT_MAX;
    for(int i=1;i*i<=n;i++){
        mini=min(mini,numSquares(n-(i*i)));
    }
    return 1+mini;
}
int main(){
    cout<<numSquares(12)<<"   "<<numSquares(13)<<endl;
}