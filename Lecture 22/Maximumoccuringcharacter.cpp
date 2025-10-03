#include<iostream>
using namespace std;
int Max(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[i]<arr[j]){
                count ++;
            }
        }
        if (count==0){
            return i;
        }
    }
}
int main(){
    string s;
    cin>>s;
    int alpha_count[26]={0};
    for(int i=0;i<s.length();i++){
        int n;
        if((s[i]>='a')&&(s[i]<='z')){
            n=s[i]-'a';
            alpha_count[n]++;
        }
        else{
            n=s[i]-'A';
            alpha_count[n]++;
        }
    }
    cout<<char('a'+Max(alpha_count,26));
}