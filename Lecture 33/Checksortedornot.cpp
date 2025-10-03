#include<iostream>
using namespace std;
bool isSorted(int arr[],int size){
    if(size==0 || size==1){
        return 1;
    }
    else if(arr[0]>arr[1]){
        return 0;
    }
    else{
        return isSorted(arr+1,size-1);
}
}
int main(){
    int nums[5]={2,4,6,8,9};
    int nums2[6]={2,7,3,98,1};
    cout<<isSorted(nums,5)<<endl;
    cout<<isSorted(nums2,56)<<endl;
}