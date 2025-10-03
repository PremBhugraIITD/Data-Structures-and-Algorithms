#include<iostream>
#include<vector>
using namespace std;
//Without DP
int solve(int startingIndex,int endingIndex,vector<int> &slices,int n){
    if(n==0||startingIndex>endingIndex){
        return 0;
    }
    int include = slices[startingIndex] + solve(startingIndex+2,endingIndex,slices,n-1);
    int exclude = solve(startingIndex+1,endingIndex,slices,n);
    return max(include,exclude);
}
int maxSizeSlices(vector<int> slices) {
    int k = slices.size();
    int ans1 = solve(0,k-2,slices,k/3); //k/3 is the number of slices available for us to eat.
    int ans2 = solve(1,k-1,slices,k/3);
    return max(ans1,ans2);
}
int main(){
    cout<<maxSizeSlices({8,9,8,6,1,1})<<endl;
}