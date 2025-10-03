#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//Without DP
int solve(vector<int> &satisfaction,int i,int time){
    if(i>=satisfaction.size()){
        return 0;
    }
    else{
        return max(time*satisfaction[i] + solve(satisfaction,i+1,time+1),solve(satisfaction,i+1,time));
    }
}
int maxSatisfaction(vector<int> satisfaction) {
    sort(satisfaction.begin(),satisfaction.end());
    return solve(satisfaction,0,1);
}
int main(){
    cout<<maxSatisfaction({-1,-8,0,5,-9})<<"   "<<maxSatisfaction({-1,-4,-5})<<endl;
}