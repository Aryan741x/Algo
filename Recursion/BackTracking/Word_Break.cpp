class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>wordset(wordDict.begin(),wordDict.end());
        vector<bool>dp(s.size()+1,false);
        dp[0]=true;//Empty String can be segmented

        for(int i=1;i<=s.size();++i){
            for(int j=0;j<i;++j){
                if(dp[j] && wordset.find(s.substr(j,i-j))!=wordset.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.size()];

    }
};
