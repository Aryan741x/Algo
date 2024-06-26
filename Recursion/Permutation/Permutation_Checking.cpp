class Solution {
public:
    void result(vector<vector<int>>&res,vector<int>nums,vector<int>c,vector<bool>check){
        if(c.size()==nums.size()){
            res.push_back(c);
            return;
        }
        for(int j=0;j<nums.size();++j){
            if(!check[j]){
                check[j]=true;
                c.push_back(nums[j]);
                result(res,nums,c,check);
                c.pop_back();
                check[j]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>c;
        vector<bool>check(nums.size(),false);
        result(res,nums,c,check);
        return res;
    }
};
