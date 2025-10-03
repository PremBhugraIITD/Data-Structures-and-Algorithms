#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
//Without DP
int solve(vector<int> &obstacles,int pos,int currlane){
    if(pos==obstacles.size()-1){
        return 0;
    }
    if(obstacles[pos+1]!=currlane){ //No need to jump
        return solve(obstacles,pos+1,currlane);
    }
    else{  //Side jump required
        int mini = INT_MAX;
        for(int i=1;i<=3;i++){
            if(i!=currlane && obstacles[pos]!=i){
                mini = min(mini,1+solve(obstacles,pos,i));
            }
        }
        return mini;
    }
}
int minSideJumps(vector<int> obstacles) {
    return solve(obstacles,0,2);
}
int main(){
    cout<<minSideJumps({0,2,1,0,3,0})<<"   "<<minSideJumps({0,1,1,3,3,0})<<endl;
}