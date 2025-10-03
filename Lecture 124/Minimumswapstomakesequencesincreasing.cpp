#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
//Without DP
int solve(vector<int>& nums1, vector<int>& nums2,int i,bool swapped){
    if(i>=nums1.size()){
        return 0;
    }
    int ans = INT_MAX;
    int prev1 = nums1[i-1];
    int prev2 = nums2[i-1];
    if(swapped){
        swap(prev1,prev2);
    }
    if(nums1[i]>prev1 && nums2[i]>prev2){ //No swap
        ans = solve(nums1,nums2,i+1,false);
    }
    if(nums2[i]>prev1 && nums1[i]>prev2){ //Swap
        ans = min(ans,1+solve(nums1,nums2,i+1,true));
    }
    return ans;
}
int minSwap(vector<int> nums1, vector<int> nums2) {
    nums1.insert(nums1.begin(),-1);
    nums2.insert(nums2.begin(),-1);
    return solve(nums1,nums2,1,false);
}
using namespace std;
int main(){
    cout<<minSwap({0,3,5,8,9},{2,1,4,6,9})<<endl;
}