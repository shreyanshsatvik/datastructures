class Solution {
public:
    int max_area(vector<int> heights)
    {
        /*
        vector<int> left_index;
        vector<int> right_index;
        stack<int> left;
        stack<int> right;
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            if(!left.empty() && arr[left.top()]>=arr[i])
            {
                left.pop();
            }
            if(left.empty())
            {
                left_index.push_back(-1);
            }
            else
            {
                left_index.push_back(left.top());
            }
            left.push(i);
        }
        for(int i=n-1;i>=0;i--)
        {
            if(!right.empty() && arr[right.top()]>=arr[i])
            {
                right.pop();
            }
            if(right.empty())
            {
                right_index.push_back(n);
            }
            else
            {
                right_index.push_back(right.top());
            }
            right.push(i);
        }
        reverse(right_index.begin(),right_index.end());
        int max_height = 0;
        for(int i=0;i<n;i++)
        {
            max_height = max(max_height,arr[i]*(right_index[i]-left_index[i]-1));
        }
        return max_height;
        */
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
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
        {
            return 0;
        }
        if(matrix.size()==1)
        {
            vector<int> arr(matrix[0].size(),0);
            for(int i=0;i<matrix[0].size();i++)
            {
                if(matrix[0][i]=='1')
                {
                    arr[i] = 1;
                }
            }
            return max_area(arr);
            
        }
       
        vector<vector<int>> arr(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix[0].size();i++)
        {
            if(matrix[0][i]=='1')
            {
                arr[0][i] =1;
                //cout<<i<<" "<<arr[0][i]<<endl;
            }
            
        }
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]=='1')
                {
                    
                    arr[i][j] = arr[i-1][j]+1;
                    //cout<<i<<" "<<j<<" "<<arr[i][j]<<endl;
                }
            }
        }
        int maxx = 0;
        for(int i=0;i<arr.size();i++)
        {
            maxx = max(maxx,max_area(arr[i]));
        }
        
        return maxx;
    }
};
