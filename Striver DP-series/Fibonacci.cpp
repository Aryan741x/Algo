#include<iostream>
#include<vector>
using namespace std;
int f(int n,vector<int>&dp){
    if(n<=1)return n;
    if(dp[n]==-1){
        return dp[n]=f(n-1,dp)+f(n-2,dp);
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    cout<<f(n,dp);
}
