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
//Recursive code
/*int f(vector<int>&dp,int index){
    if(index==0){
        return 0;
    }
    if(index==1){
        int left=f(dp,index-1)+abs(dp[index]-dp[index-1]);
        return left;
    }
    else{
        int left=f(dp,index-1)+abs(dp[index]-dp[index-1]);
        int right=f(dp,index-2)+abs(dp[index]-dp[index-2]);
        return min(left,right);
    }
}*/

//Dp code
int f(vector<int>&dp,vector<int>&val,int index){
    if(index==0)return 0;
    int left;
    if(dp[index-1]!=-1){
        left=dp[index-1]+abs(val[index]-dp[index-1]);
    }
    else{
        left=f(dp,val,index-1)+abs(val[index]-val[index-1]);
    }
    int right=1e9;
    if(index>1){
        if(dp[index-2]!=-1){
            right=dp[index-2]+abs(val[index]-val[index-2]);
        }
        else{
            right=f(dp,val,index-2)+abs(val[index]-val[index-2]);
        }
    }
    dp[index]=min(right,left);
    return min(left,right);
}

int main(){
    int n;
    cin>>n;
    vector<int>val(n);
    vector<int>dp(n,-1);
    for(int i=0;i<n;++i){
        cin>>val[i];
    }
    cout<<f(dp,val,n-1)<<endl;
}
