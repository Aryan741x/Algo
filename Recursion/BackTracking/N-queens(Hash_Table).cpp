//Optimize version
class Solution {
public:
    void result(vector<vector<string>>&res,int i,vector<string>e,int n,vector<int>&left,vector<int>&upperleft,vector<int>&lowerleft){
        if(i==n){
            res.push_back(e);
            return;
        }
        for(int j=0;j<n;++j){
            if(left[j]==0 && upperleft[n-1+i-j]==0 && lowerleft[i+j]==0){
                e[i][j]='Q';
                left[j]=1;
                upperleft[n-1+i-j]=1;
                lowerleft[i+j]=1;
                result(res,i+1,e,n,left,upperleft,lowerleft);
                left[j]=0;
                upperleft[n-1+i-j]=0;
                lowerleft[i+j]=0;
                e[i][j]='.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        string s(n,'.');
        vector<string>e(n,s);
        vector<int>left(n,0);
        vector<int>upperleft(n+n,0);
        vector<int>lowerleft(n+n,0);
        result(res,0,e,n,left,upperleft,lowerleft);
        return res;
    }
    
};
