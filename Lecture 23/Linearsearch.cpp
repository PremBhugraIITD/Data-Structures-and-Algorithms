#include<iostream>
using namespace std;
bool isPresent(int target,int r,int arr[][4]){
    for(int i=0;i<r;i++){
        for(int j=0;j<4;j++){
            if(arr[i][j]==target){
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    int nums[3][4]={{1,2,3,4},{0,0,23,11},{34,11,23,14}};
    cout<<isPresent(11,3,nums)<<endl;
    cout<<isPresent(22,3,nums);
}