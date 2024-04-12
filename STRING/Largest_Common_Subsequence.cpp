#include<iostream>
#include<vector>
using namespace std;
void f(vector<vector<int>>&vec,vector<vector<int>>&dis,int m,int n,string x,string y){
    for(int i=1;i<m;++i){
        for(int j=1;j<n;++j){
            if(x[i-1]==y[j-1]){
                vec[i][j]=vec[i-1][j-1]+1;
                dis[i][j]=3;
            }
            else if(vec[i-1][j]>vec[i][j-1]){
                vec[i][j]=vec[i-1][j];
                dis[i][j]=1;
            }
            else{
                vec[i][j]=vec[i][j-1];
                dis[i][j]=2;
            }
        }
    }
}
void display(vector<vector<int>>&ans,string x,int i,int j){
    if(i==0||j==0)return;
    if(ans[i][j]==3){
        display(ans,x,i-1,j-1);
        cout<<x[i-1];
    }
    else if(ans[i][j]==2){
        display(ans,x,i,j-1);
    }
    else{
        display(ans,x,i-1,j);
    }
}
int main(){
    string x,y;
    cin>>x>>y;
    vector<vector<int>>vec(x.size()+1,vector<int>(y.size()+1,0));
    vector<vector<int>>dir(x.size()+1,vector<int>(y.size()+1,0));
    f(vec,dir,x.size()+1,y.size()+1,x,y);
    for(int i=0;i<x.size()+1;++i){
        for(int j=0;j<y.size()+1;++j){
            cout<<dir[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<x.size()+1;++i){
        for(int j=0;j<y.size()+1;++j){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    display(dir,x,x.size(),y.size());
}
