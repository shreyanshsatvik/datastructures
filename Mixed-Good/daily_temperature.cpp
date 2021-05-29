class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        stack<pair<int,int>> st;
        vector<int> ans(temp.size(),0);
        if(temp.size()==0)
        {
            return ans;
        }
        
        st.push(make_pair(temp[temp.size()-1],0));
        for(int i=temp.size()-2;i>=0;i--)
        {
            int count = 1;
            while(!st.empty() && st.top().first<=temp[i])
            {
                count += st.top().second;
                st.pop();
            }
            if(st.empty())
            {
                
                st.push(make_pair(temp[i],0));
            }
            else
            {
                ans[i] = count;
                st.push(make_pair(temp[i],count));
            }
        
            
        }
        return ans;
        
    }
};




         
         
         
         
         
