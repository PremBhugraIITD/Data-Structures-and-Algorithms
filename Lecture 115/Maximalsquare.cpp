#include<iostream>
#include<vector>
using namespace std;
//Without DP
int solve(vector<vector<int>> matrix,int i,int j,int &maxi){
    if(i>=matrix.size() || j>=matrix[0].size()){
        return 0;
    }
    int right = solve(matrix,i,j+1,maxi);
    int diagonal = solve(matrix,i+1,j+1,maxi);
    int down = solve(matrix,i+1,j,maxi);
    if(matrix[i][j]==1){
        int ans = 1+min(right,min(diagonal,down));
        maxi = max(maxi,ans);
        return ans;
    }
    else{
        return 0;
    }
}
int maximalSquare(vector<vector<int>> matrix){
    int maxi = 0;
    solve(matrix,0,0,maxi);
    return maxi*maxi;
}
int main(){
    cout<<maximalSquare({{1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}})<<endl;
}