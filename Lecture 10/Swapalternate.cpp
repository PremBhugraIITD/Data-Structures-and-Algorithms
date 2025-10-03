#include<iostream>
using namespace std;
void printArray(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<endl;
    }
    }
void swapalternate(int arr[],int size){
    for (int i = 0; i < size; i+=2)
    {
           if((i+1)==size){
            break;
        }
        int temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
    }
    printArray(arr,size);    
}
int main(){
    int numbers1[5]={1,2,7,8,5};
    int numbers2[6]={1,2,3,4,5,6};
    cout<<"numbers1:"<<endl;
    swapalternate(numbers1,5);
    cout<<"numbers2:"<<endl;
    swapalternate(numbers2,6);
}