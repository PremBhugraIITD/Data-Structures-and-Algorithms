#include<iostream>
#include<limits.h>
using namespace std;
//Without DP
int solve(int n,int x,int y,int z){
	if(n==0){
        return 0;
    }
    else if(n<0){
        return INT_MIN;
    }
    int ans1 = solve(n-x,x,y,z);
    int ans2 = solve(n-y,x,y,z);
    int ans3 = solve(n-z,x,y,z);
    if(ans1<0){
        ans1 = INT_MIN;
    }
    if(ans2<0){
        ans2 = INT_MIN;
    }
    if(ans3<0){
        ans3 = INT_MIN;
    }
    return 1 + max(ans1,max(ans2,ans3));
}
int cutSegments(int n, int x, int y, int z) {
    int ans = solve(n,x,y,z);
    if(ans<0){
        return 0;
    }
    return ans;
}
int main(){
    cout<<cutSegments(8,1,4,4)<<endl;
}