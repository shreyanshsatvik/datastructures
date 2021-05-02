class Solution{
	
	public:
	int minimumCost(int ar[], int N, int W) 
	{ 
        // Your code goes here
        vector<int> cost(ar,ar+N);
        vector<int> wt,val;
        if(N==0)
        {
            return -1;
        }
        for(int i=0;i<N;i++)
        {
               
                val.push_back(cost[i]);
                wt.push_back(i+1);
        
        }
        N = val.size();
        
        vector<vector<int>> arr(N+1,vector<int>(W+1,999999999));
        
        for(int i = 0;i<=N;i++)
            arr[i][0]=0;
        for(int j=1;j<=W;j++)
            arr[0][j]=999999999;
        
        arr[0][0] = 0;

        for(int i=1;i<N+1;i++)
        {
            for(int j=1;j<W+1;j++)
            {
                
                if(wt[i-1]==-1)
                {
                    arr[i][j] = INT_MAX;
                }
                if(wt[i-1]>j || val[i-1]==-1)
                {
                    arr[i][j] = arr[i-1][j];
                }
                else
                {
                    arr[i][j] = min(arr[i-1][j],(val[i-1]+arr[i][j-i]));
                }
                   
                
            }
        }
        
       if(arr[N][W]<0 || arr[N][W]==999999999)
            return -1;
        else
            return arr[N][W];
        
        
        
	} 

};
