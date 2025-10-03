#include<iostream>
using namespace std;
bool linearsearch(int arr[],int size,int key){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==key){
            return true;
        }
    }
    return false;
}
int main(){
    int numbers[6]={2,1,91,-3,4,1};
    if(linearsearch(numbers,6,5)){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Absent"<<endl;
    }
    if(linearsearch(numbers,6,-3)){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Absent"<<endl;
    }
    if(linearsearch(numbers,6,1)){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Absent"<<endl;
    }
}