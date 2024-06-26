class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
        unordered_map<int,int>m;
        for(int num:nums)m[num]++;
        vector<int>c;
        result(res,c,m,nums.size());
        return res;
    }
    void result(vector<vector<int>>&res,vector<int>&c,unordered_map<int,int>&m,int n){
        if(c.size()==n){
            res.push_back(c);
            return;
        }
        for(auto& item:m){
            int num=item.first;
            int count=item.second;
            if(count==0)continue;
            c.push_back(num);
            m[num]--;
            result(res,c,m,n);
            c.pop_back();
            m[num]++;
        }
    }
};
