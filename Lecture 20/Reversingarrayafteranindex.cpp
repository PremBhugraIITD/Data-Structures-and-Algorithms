#include<iostream>
using namespace std;
void printArray(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<endl;
    }
    }
void Reverse(int arr[],int size,int m){
    int l=m+1;
    int u=size-1;
    while(l<=u){
        swap(arr[l],arr[u]);
        l++;u--;
    }
    printArray(arr,size);
}
int main(){
    int numbers1[6]={2,7,4,1,9,4};
    int numbers2[7]={7,2,87,23,4,12,4};
    int numbers3[6]={1,2,3,4,5,6};
    Reverse(numbers1,6,2);
    Reverse(numbers2,7,4);
    Reverse(numbers3,6,3);
}