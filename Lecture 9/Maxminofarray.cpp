#include<iostream>
using namespace std;
int Max(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[i]<arr[j]){
                count ++;
            }
        }
        if (count==0){
            return arr[i];
        }
    }
}
int Min(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[i]>arr[j]){
                count ++;
            }
        }
        if (count==0){
            return arr[i];
        }
    }
}
int main(){
    int test1[9] = {3,4,76,12,14,6,2,76,4};
    int test2[8] = {1,1,3,4,4,3,5,3};
    cout<<Max(test1,9)<<endl<<Max(test2,3)<<endl;;
    cout<<Min(test1,9)<<endl<<Min(test2,3);
}