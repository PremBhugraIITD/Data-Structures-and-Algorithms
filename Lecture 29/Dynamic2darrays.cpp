#include<iostream>
using namespace std;
int main(){
    int m,n;
    cin >> m >> n;
    //Creation of a 2-D array of m rows and n columns
    int **ptr = new int *[m];
    for(int i=0;i<m;i++){
        ptr[i] = new int[n];
    }
    //Taking inputs
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>ptr[i][j];
        }
    }
    //Printing the array
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<ptr[i][j]<<" ";
        }
        cout<<endl;
    }
    //Releasing heap memory because unlike stack memory, it doesn't get cleared automatically
    for(int i=0;i<m;i++){
        delete []ptr[i];
    }
    delete []ptr;
}