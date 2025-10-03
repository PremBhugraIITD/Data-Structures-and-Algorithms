#include<iostream>
#include<vector>
using namespace std;
//Without DP
int solve(vector<int> days,vector<int> cost,int i){
    if(i>=days.size()){
        return 0;
    }
    else if(i==days.size()-1){
        return min(cost[0],min(cost[1],cost[2]));
    }
    int temp = i;
    temp++;
    int ans1 = cost[0]+solve(days,cost,temp);
    temp = i;
    while(temp<days.size() && days[temp]<=days[i]+6){
        temp++;
    }
    int ans2 = cost[1]+solve(days,cost,temp);
    temp=i;
    while(temp<days.size() && days[temp]<=days[i]+29){
        temp++;
    }
    int ans3 = cost[2]+solve(days,cost,temp);
    return min(ans1,min(ans2,ans3));
}
int mincostTickets(vector<int> days, vector<int> costs) {
    return solve(days,costs,0);
}
int main(){
    cout<<mincostTickets({1,4,6,7,8,20},{2,7,15})<<endl;
}