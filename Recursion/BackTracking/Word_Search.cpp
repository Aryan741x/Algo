class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        int index=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(board[i][j]==word[index]){
                    if(searchNext(board,word,i,j,index)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool searchNext(vector<vector<char>>&board,string word,int row,int col,int index){
        //Base Case
        if(index==word.length())return true;
        if(row<0 || col<0 || row==board.size()||col==board[0].size() || board[row][col]!=word[index] || board[row][col]=='@')return false;
        
        //BackTrack Code
        char temp=board[row][col];
        board[row][col]='@';//Make the visited array marked as @

        if(searchNext(board,word,row,col-1,index+1)||searchNext(board,word,row,col+1,index+1)||searchNext(board,word,row-1,col,index+1)||searchNext(board,word,row+1,col,index+1)){
            return true;
        }

        board[row][col]=temp;
        return false;
    }
};
