//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int>col(n,0);
        bool r=result(col,graph,m,n,0);
        return r;
    }
    bool result(vector<int>col,bool graph[101][101],int m,int n,int i){
        if(i==col.size()){
            return true;
        }
        for(int j=1;j<=m;++j){
            if(isValid(i,graph,j,col)){
                col[i]=j;
                if(result(col,graph,m,n,i+1)){
                    return true;   
                }
                col[i]=0;
            }
        }
        return false;
    }
    bool isValid(int i,bool graph[101][101],int j,vector<int>col){
        for(int k=0;k<col.size();++k){
            if(graph[i][k]){
                if(col[k]==j){
                    return false;
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
