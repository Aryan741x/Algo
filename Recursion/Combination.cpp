class Solution {
public:
    void result(vector<int>&c,vector<vector<int>>&r,vector<int>&cur,int t,int sum,int i){
        if(sum>t||i==c.size())return;
        if(sum==t){
            r.push_back(cur);
            return;
        }
        cur.push_back(c[i]);
        result(c,r,cur,t,sum+c[i],i);
        cur.pop_back();
        result(c,r,cur,t,sum,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>cur;
        vector<vector<int>>res;
        result(candidates,res,cur,target,0,0);
        return res;
    }
};
