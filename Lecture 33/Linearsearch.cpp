#include<iostream>
using namespace std;
bool linear_search(int arr[],int size,int target){
    if(size==0){
        return false;
    }
    else if(arr[0]==target){
        return true;
    }
    else{
        return linear_search(arr+1,size-1,target);
}
}
int main(){
    int nums[6]={12,13,62,454,23,2};
    cout<<linear_search(nums,6,62)<<endl;
    cout<<linear_search(nums,6,23)<<endl;
    cout<<linear_search(nums,6,444)<<endl;
}