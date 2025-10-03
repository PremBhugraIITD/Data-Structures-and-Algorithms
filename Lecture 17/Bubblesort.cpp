#include<iostream>
using namespace std;
void printArray(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<endl;
    }
    }
void Bubblesort(int arr[],int size){
    for(int j=size-1;j>=0;j--){
        for(int i=0;i<j;i++){
            if (arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
            }
        }
        }
}
int main(){
    int numbers1[6]={10,1,7,6,14,9},numbers2[5]={45,12,6,79,84},numbers3[8]={45,5,5,79,84,79,12,7};
    Bubblesort(numbers1,6);
    printArray(numbers1,6);
    Bubblesort(numbers2,5);
    printArray(numbers2,5);
    Bubblesort(numbers3,8);
    printArray(numbers3,8);
}