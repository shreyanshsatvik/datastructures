class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int gass;
        for(int i=0;i<cost.size();i++)
        {
            
            if(gas[i]-cost[i]<0)
            {
                continue;
            }
            gass = gas[i];    
            int j = cost.size();
            for(int k=i;k<cost.size();k++)
            {
                if(j<=0)
                {
                    break;
                }
                if(gass-cost[k]<0)
                {
                    break;
                }
                if(k+1==cost.size())
                {
                    gass = gass + gas[0] - cost[k];
                    k=-1;
                }
                else
                {
                    gass = gass + gas[k+1] - cost[k];
                }
                
                j--;
            }
            
            if(gass>=0 && j<=0)
            {
                return i;
            }
            
        }
        
        return -1;
        
    }
};

