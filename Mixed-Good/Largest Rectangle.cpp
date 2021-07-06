
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> left;
        stack<int> right;
        vector<int> l_limit;
        vector<int> r_limit;
        
        for(int i=0;i<heights.size();i++)
        {
            while(!left.empty() && heights[i]<=heights[left.top()])
            {
                left.pop();
            }
            if(left.empty())
            {
                l_limit.push_back(-1);
            }
            else
            {
                l_limit.push_back(left.top());
            }
            left.push(i);
        }
        int n= heights.size();
        
        for(int i=n-1;i>=0;i--)
        {
            while(!right.empty() && heights[right.top()]>=heights[i])
            {
                right.pop();
            }
            if(right.empty())
            {
                r_limit.push_back(n);
            }
            else
            {
                r_limit.push_back(right.top());
            }
            right.push(i);
            
        }

        int max_height = 0;
        reverse(r_limit.begin(),r_limit.end());
        
        
        for(int i=0;i<heights.size();i++)
        {
            max_height = max(max_height,heights[i]*(r_limit[i]-l_limit[i]-1));
        }
    
        return max_height;
        
        
        
    }
};
