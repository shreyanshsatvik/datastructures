class Solution {
public:
    vector<vector<bool>> visited;
    vector<vector<int>> ans;
    vector<int> output;
    
    void bfs(int i,int j,int p,int q,int N,int min)
    {
        if(i==p && j==q)
        {
            
            output.push_back(ans.size());
            return;
        }
        if(visited[i][j])
        {
            return;
        }
        visited[i][j] = true;
        if(i+2<=N && j+1<=N )
        {
            ans.push_back(vector<int>{i+2,j+1});
            bfs(i+2,j+1,p,q,N,min);
            ans.pop_back();
        }
        if(i+2<=N && j-1>=1 )
        {
            ans.push_back(vector<int>{i+2,j-1});
            bfs(i+2,j-1,p,q,N,min);
            ans.pop_back();
        }
        if(i-2>=1 && j+1<=N )
        {
            ans.push_back(vector<int>{i-2,j+1});
            bfs(i-2,j+1,p,q,N,min);
            ans.pop_back();
        }
        if(i-2>=1 && j-1>=1 )
        {
            ans.push_back(vector<int>{i-2,j-1});
            bfs(i-2,j-1,p,q,N,min);
            ans.pop_back();
        }
        if(i+1<=N && j+2<=N )
        {
            ans.push_back(vector<int>{i+1,j+2});
            bfs(i+1,j+2,p,q,N,min);
            ans.pop_back();
        }
        if(i-1>=1 && j+2<=N)
        {
            ans.push_back(vector<int>{i-1,j+2});
            bfs(i-1,j+2,p,q,N,min);
            ans.pop_back();
        }
        if(i+1<=N && j-2>=1 )
        {
            ans.push_back(vector<int>{i+1,j-2});
            bfs(i+1,j-2,p,q,N,min);
            ans.pop_back();
        }
        if(i-1>=1 && j-2>=1 )
        {
            ans.push_back(vector<int>{i-1,j-2});
            bfs(i-1,j-2,p,q,N,min);
            ans.pop_back();
        }
        
        visited[i][j] = false;
    
    return;
        
        
        
        
    }
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	    
	    
	    ans.push_back(KnightPos);
	    visited = vector<vector<bool>>(N,vector<bool>(N,false));
	    bfs(KnightPos[0],KnightPos[1],TargetPos[0],TargetPos[1],N,INT_MAX);
	    sort(output.begin(),output.end());
	    return output[0];
	    
	    
	    
	    
	    
	    
	    
	}
};
