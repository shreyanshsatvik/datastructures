class Solution {
public:
    bool bfs(vector<vector<char>>& board,vector<vector<bool>>& visited, string word,int i,int j,int k)
    {
        if(k==word.size()-1)
        {
            return true;
        }
        visited[i][j] = true;
        if(j+1<board[0].size() && board[i][j+1]==word[k+1] && visited[i][j+1]==false)
        {
            if(bfs(board,visited,word,i,j+1,k+1)==true)
            {
                return true;
            }
            visited[i][j+1] = false;
        }
        if(i-1>=0 && board[i-1][j]==word[k+1] && visited[i-1][j]==false)
        {
            if(bfs(board,visited,word,i-1,j,k+1)==true)
            {
                return true;
            }
            visited[i-1][j] = false;
        }
        if(j-1>=0 && board[i][j-1]==word[k+1] && visited[i][j-1]==false)
        {
            if(bfs(board,visited,word,i,j-1,k+1)==true)
            {
                return true;
            }
            visited[i][j-1] = false;
        }
        if(i+1<board.size() && board[i+1][j]==word[k+1] && visited[i+1][j]==false)
        {
            if(bfs(board,visited,word,i+1,j,k+1)==true)
            {
                return true;
            }
            visited[i+1][j] = false;
        }
        visited[i][j] = false;

        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0] && visited[i][j]==false)
                {
                    if(bfs(board,visited,word,i,j,0))
                    {
                        return true;
                    }
                }
            }  
        }
        return false;      
    }
};
