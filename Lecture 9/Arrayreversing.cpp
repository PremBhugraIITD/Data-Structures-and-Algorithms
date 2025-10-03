#include<iostream>
using namespace std;
void printArray(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<endl;
    }
    }
int main(){
    int temp;
    int numbers[9]={2,5,12,78,21,23,6,78,6};
    for(int i=0;i<(9/2);i++){
        temp=numbers[i];
        numbers[i]=numbers[8-i];
        numbers[8-i]=temp;
    }
    printArray(numbers,9);
}