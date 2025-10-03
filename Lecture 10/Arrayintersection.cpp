#include<iostream>
#include<vector>
using namespace std;
int main(){
    int num1[5]={2,4,9,23,43};
    int num2[9]={3,4,23,43,56,234,543,1234,1235};
    vector<int> intersection;
    for(int i=0;i<5;i++){
        for(int j=0;j<9;j++){
            if (num1[i]==num2[j]){
                intersection.push_back(num1[i]);
            }
        }    
    }
    for(auto k:intersection){
        cout<<k<<" ";
    }
}