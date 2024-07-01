//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>res;
        string s;
        vector<vector<bool>>Check(n,vector<bool>(n,false));
        Check[0][0]=true;
        if(m[0][0]==0)return res;
        result(s,res,0,0,m,n,Check);
        return res;
    }
    void result(string s,vector<string>&res,int i,int j,vector<vector<int>>m,int n,vector<vector<bool>>&Check){
        if(i==n-1 && j==n-1){
            res.push_back(s);
            return;
        }
        if(i+1!=n && m[i+1][j]==1 && !Check[i+1][j]){
            s.push_back('D');
            Check[i+1][j]=true;
            result(s,res,i+1,j,m,n,Check);
            s.pop_back();
            Check[i+1][j]=false;
        }
        if(j+1!=n && m[i][j+1]==1 && !Check[i][j+1]){
            s.push_back('R');
            Check[i][j+1]=true;
            result(s,res,i,j+1,m,n,Check);
            s.pop_back();
            Check[i][j+1]=false;
        }
        if(i!=0 && m[i-1][j]==1 && !Check[i-1][j]){
            s.push_back('U');
            Check[i-1][j]=true;
            result(s,res,i-1,j,m,n,Check);
            s.pop_back();
            Check[i-1][j]=false;
        }
        if(j!=0 && m[i][j-1]==1 && !Check[i][j-1]){
            s.push_back('L');
            Check[i][j-1]=true;
            result(s,res,i,j-1,m,n,Check);
            s.pop_back();
            Check[i][j-1]=false;
        }
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
