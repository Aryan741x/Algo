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
int f(int index,vector<int>&val,vector<int>&dp){
    if(index==0)return 0;
    int right=1e9;
    int left;
    if(dp[index-1]!=-1){left=dp[index-1]+abs(val[index]-val[index-1]);}
    else{left=f(index-1,val,dp)+abs(val[index]-val[index-1]);}
    if(index>1){
        if(dp[index-2]!=-1){right=dp[index-2]+abs(val[index]-val[index-2]);}
        else{right=f(index-2,val,dp)+abs(val[index]-val[index-2]);}
    }
    return min(left,right);
}
int main(){
    int n;
    cin>>n;
    vector<int>val(n+1);
    vector<int>dp(n+1,-1);
    for(int i=0;i<n;++i){
        cin>>val[i];
    }
    cout<<f(n-1,val,dp);
}
