int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.size();
		    vector<vector<int>> arr(n+1,vector<int>(n+1,0));
		    for(int i=1;i<n+1;i++)
		    {
		        for(int j=1;j<n+1;j++)
		        {
		            
		            if(str[i-1]==str[j-1] && i!=j)
		            {
		                arr[i][j] = arr[i-1][j-1]+1;
		            }
		            else
		            {
		                arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
		            }
		        }
		    }
		    return arr[n][n];
