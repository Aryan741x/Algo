#include<iostream>
#include<vector>
using namespace std;
void result(vector<vector<char>>&res,vector<char>c,int n,int i){
    if(i==n){
        res.push_back(c);
        return;
    }
    c.push_back('0');
    result(res,c,n,i+1);
    c.pop_back();
    c.push_back('1');
    result(res,c,n,i+1);
}
int main(){
    int n;
    cin>>n;
    vector<vector<char>>res;
    vector<char>c;
    result(res,c,n,0);
    for(auto it:res){
        for(auto ch:it){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}
