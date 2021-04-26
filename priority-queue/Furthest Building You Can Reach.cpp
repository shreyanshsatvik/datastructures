class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>> que;
        int i=0;
        int diff;
        while(que.size()<ladders && i<heights.size()-1)
        {
            diff = heights[i+1]-heights[i];
            if(diff<=0)
            {
                i++;
                continue;
            }
            que.push(diff);
            i++;
            
        }
        for(;i<heights.size()-1;i++)
        {
            diff = heights[i+1]-heights[i];
            if(diff>0)
            {
                if(!que.empty() && que.top()<diff)
                {
                    bricks = bricks - que.top();
                    que.pop();
                    que.push(diff);
                }
                else
                {
                    bricks = bricks - diff;
                }
            }
            if(bricks<0)
            {
                return i;
            }
                
        }
        return i;
        
        
    }
};
