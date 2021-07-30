class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
    for(int k=0;k<matrix.size();k++)
	    {
	        for(int i=0;i<matrix.size();i++)
	        {
	            for(int j=0;j<matrix.size();j++)
	            {
	                if(matrix[i][k]==INT_MAX || matrix[k][j]==INT_MAX )continue;
	                matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }
    }
};
