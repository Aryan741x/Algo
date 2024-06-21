#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void Sub(int n,vector<int>vec,queue<int>s,int i){
    if(i==n){
        while(!s.empty()){
            cout<<s.front()<<" ";
            s.pop();
        }
        cout<<endl;
        return;
    }
    Sub(n,vec,s,i+1);
    s.push(vec[i]);
    Sub(n,vec,s,i+1);
}
int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;++i){
        cin>>vec[i];
    }
    queue<int>s;
    Sub(n,vec,s,0);
}
