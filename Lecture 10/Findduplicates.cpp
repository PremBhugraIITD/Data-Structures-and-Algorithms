#include<iostream>
using namespace std;
int main(){
    int numbers[9]={8,7,2,5,4,7,1,3,6};
    for(int i=0;i<9;i++){
        int count=0;
        for(int j=0;j<9;j++){
            if(numbers[i]==numbers[j]){
                count++;
            }
        }
        if(count==2){
            cout<<numbers[i];
            break;
        }
    }
}