#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int min(int a,int b){
    if(a>b){
        return b;
    }
    else{
        return a;
    }
}
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>val(n+1);
    vector<int>dp(n+1,-1);
    for(int i=0;i<n;++i){
        cin>>val[i];
    }
    dp[0]=0;
    int fs,ss;
    for(int i=1;i<n;++i){
        ss=1e9;
        fs=dp[i-1]+abs(val[i]-val[i-1]);
        if(i>1){
            ss=dp[i-2]+abs(val[i]-val[i-2]);
        }
        if(i==1){dp[i]=fs;continue;}
        dp[i]=max(fs,ss);
    }
    cout<<dp[n-1]<<endl;
}
