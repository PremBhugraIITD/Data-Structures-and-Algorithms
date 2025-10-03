#include<iostream>
#include<queue>
using namespace std;
int minimum_cost(int arr[],int size){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<size;i++){
        pq.push(arr[i]);
    }
    int ans=0;
    while(pq.size()>1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int sum = a+b; //It is the sum of the two minimum node values in the heap
        ans+=sum;
        pq.push(sum);
    }
    return ans;
}
//TC=O(nlog(n))
//SC=O(n)
int main(){
    int nums[5] = {4,2,7,6,9};
    cout<<minimum_cost(nums,5)<<endl;
}