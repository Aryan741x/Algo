class Solution {
public:
    bool isSafe(int i,int j,vector<string>e,int n){
        int row=i;
        int col=j;
        while(row>=0 && col>=0){
            if(e[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        row=i;
        col=j;
        while(row>=0){
            if(e[row][col]=='Q'){
                return false;
            }
            row--;
        }
        row=i;
        col=j;
        while(col<n && row>=0){
            if(e[row][col]=='Q'){
                return false;
            }
            row--;
            col++;
        }
        return true;
    }
    void result(vector<vector<string>>&res,int i,vector<string>e,int n){
        if(i==n){
            res.push_back(e);
            return;
        }
        for(int j=0;j<n;++j){
            if(isSafe(i,j,e,n)){
                e[i][j]='Q';
                result(res,i+1,e,n);
                e[i][j]='.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        string s(n,'.');
        vector<string>e(n,s);
        result(res,0,e,n);
        return res;
    }
    
};
