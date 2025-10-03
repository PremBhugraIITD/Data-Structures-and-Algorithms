#include<iostream>
#include<limits.h>
using namespace std;
int main(){
    int maxi=INT_MIN;
    int row =-1;
    int arr[3][4]={{1,2,3,4},{11,22,33,44},{9,4,5,23}};
    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<4;j++){
            sum+=arr[i][j];
        }
        if(sum>=maxi){
            maxi=sum;
            row=i;
        }
    }
    cout<<maxi<<" "<<row;
}