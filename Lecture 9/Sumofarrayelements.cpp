#include<iostream>
using namespace std;
int main(){
    int numbers[5]={3,4,1,7,8};
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum+=numbers[i];
    }
    cout<<sum;
}