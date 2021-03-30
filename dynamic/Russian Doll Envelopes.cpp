class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        
        int p = envelopes.size();
        sort(envelopes.begin(),envelopes.end());
        vector<int> l(p,1);
        for(int i=1;i<p;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1] && l[i]<l[j]+1 )
                {
                    l[i] = l[j]+1;
                }
            }
        }
        
        return *max_element(l.begin(),l.end());
        
        
        
        
    }
};
