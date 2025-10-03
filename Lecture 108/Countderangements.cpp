#include<iostream>
using namespace std;
//Without DP
int countDerangements(int n) {
    if(n<=1){
        return 0;
    }
    else if(n==2){
        return 1;
    }
    else{
        return ((n-1)*(countDerangements(n-1) + countDerangements(n-2)));
    }
}
int main(){
    cout<<countDerangements(4)<<"  "<<countDerangements(3)<<endl;
}