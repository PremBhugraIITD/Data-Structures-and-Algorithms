#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
//Without DP
int solve(vector<int> &value,int i,int j){
    if(j-i==1){
        return 0;
    }
    else if(j-i==2){
        return value[i]*value[j]*value[i+1];
    }
    int mini = INT_MAX;
    for(int k=i+1;k<j;k++){
        mini = min(mini,value[i]*value[j]*value[k] + solve(value,i,k) + solve(value,k,j));
    }
    return mini;
}
int minScoreTriangulation(vector<int> values) {
    return solve(values,0,values.size()-1);
}
int main(){
    cout<<minScoreTriangulation({1,3,1,4,1,5})<<endl;
}