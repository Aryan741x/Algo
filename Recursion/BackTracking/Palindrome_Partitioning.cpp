class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>path;
        result(s,res,path,0);
        return res;
    }
    void result(string s,vector<vector<string>>&res,vector<string>&path,int i){
        if(i==s.size()){
            res.push_back(path);
            return;
        }
        for(int j=i;j<s.size();++j){
            if(isPalindrome(s,i,j)){
                path.push_back(s.substr(i,j-i+1));
                result(s,res,path,j+1);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
