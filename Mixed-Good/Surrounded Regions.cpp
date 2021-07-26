class Solution {
public:
    void bfs(vector<vector<char>> &board,int i,int j)
    {
        int n = board.size();
        int m = board[0].size();
        
        if(board[i][j]=='O')
        {
            board[i][j] = 'Y';
        }
        else
        {
            return;
        }
        
        if(j+1<m)
        {
            bfs(board,i,j+1);
        }
        if(i-1>=0)
        {
            bfs(board,i-1,j);
        }
        if(i+1<n)
        {
            bfs(board,i+1,j);
        }
        if(j-1>=0)
        {
            bfs(board,i,j-1);
        }
        
        
        return;
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++)
        {
            bfs(board,i,0);
            if(m>1)
                bfs(board,i,m-1);
        }
        for(int j=0;j<m;j++)
        {
            bfs(board,0,j);
            if(n>1)
                bfs(board,n-1,j);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O')
                {
                    board[i][j]= 'X';
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='Y')
                {
                    board[i][j]= 'O';
                }
            }
        }
    }
};
