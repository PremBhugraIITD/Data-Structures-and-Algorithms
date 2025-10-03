#include<iostream>
using namespace std;
void printArray(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<endl;
    }
    }
void update(int arr[],int size){
    printArray(arr,size);
    arr[0]=120;
    printArray(arr,size);
}
int main(){
    int numbers[5]={1,2,3,4,5};
    printArray(numbers,5);
    update(numbers,5);
    printArray(numbers,5);
}