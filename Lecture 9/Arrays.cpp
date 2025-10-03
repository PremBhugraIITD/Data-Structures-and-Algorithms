#include<iostream>
using namespace std;
void printArray(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<endl;
    }
    }
void printArray2(char arr[],int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<endl;
    }
}
int main(){
    int first[5];
    cout<< first[3]<<endl;
    int second[5] = {3,4,5,8,9};
    cout<< second[3] << endl << second[7] <<endl;
    int third[5] = {3,4};
    cout<<"Third"<<endl;
    printArray(third,5);
    int fourth[5]={0};
    cout<<"Fourth"<<endl;
    printArray(fourth,5);
    int fifth[5]={4};
    cout<<"Fifth"<<endl;
    printArray(fifth,5);
    int sixth[]={3,4,1};
    cout<<"Sixth"<<endl;
    printArray(sixth,5);
    char one[5];
    cout<<"One"<<endl;
    printArray2(one,5);
    char two[5]={'a','b','c','e','f'};
    cout<<"Two"<<endl;
    printArray2(two,5);
    char three[5]={'x','y'};
    cout<<"Three"<<endl;
    printArray2(three,5);
    char four[5]={'m'};
    cout<<"Four"<<endl;
    printArray2(four,5);
    char five[]={'m','n','o'};
    cout<<"Five"<<endl;
    printArray2(five,5);
    char six[5]={" "};
    cout<<"Six"<<endl;
    printArray2(six,5);
}