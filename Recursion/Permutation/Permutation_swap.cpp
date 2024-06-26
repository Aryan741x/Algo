class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        result(res,nums,0);
        return res;
    }
    void result(vector<vector<int>>&res,vector<int>nums,int i){
        if(i==nums.size()-1){
            res.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();++j){
            swap(nums[j],nums[i]);
            result(res,nums,i+1);
            swap(nums[j],nums[i]);
        }
    }
};
