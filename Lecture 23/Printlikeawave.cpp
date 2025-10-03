#include<iostream>
using namespace std;
int main(){
    int nums[3][4]={{1,2,3,4},{0,0,23,11},{34,11,23,14}};
    for(int j=0;j<4;j++){
        if(j%2==0){
        for(int i=0;i<3;i++){
            cout<<nums[i][j]<<" ";
        }}
        else{
            for(int i=3-1;i>=0;i--){
                cout<<nums[i][j]<<" ";
            }
        }
    }
}