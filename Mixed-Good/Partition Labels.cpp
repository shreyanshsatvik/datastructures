class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        vector<int> start(26,-1);
        vector<int> end(26,-1);
        for(int i=0;i<s.size();i++)
        {
            if(start[s[i]-'a']==-1)
            {
                start[s[i]-'a'] = i;
            }
            end[s[i]-'a'] = i;
            
        }
        /*
        for(int i=s.size()-1;i>=0;i--)
        {
            if(end[s[i]-'a']==-1)
            {
                end[s[i]-'a'] = i;
            }
            else
            {
                start[s[i]-'a'] =i;
            }
        
        }
        */
        int lptr,rptr;

        for(int i=0;i<s.size();i++)
        {
            if(start[s[i]-'a']==end[s[i]-'a'])
            {
                ans.push_back(1);
            }
            else
            {
                
                 lptr = start[s[i]-'a'];
                 rptr = end[s[i]-'a'];
                 break;
                 
            }
        }
        //cout<<lptr<<rptr;
        if(rptr==s.size()-1)
        {
            ans.push_back(rptr-lptr+1);
        }
        while(rptr<s.size()-1)
        {
            for(int i=lptr;i<rptr;i++)
            {
    
                if(end[s[i]-'a']>rptr)
                {
                    rptr = end[s[i]-'a'];
                    
                }
                
            }
            if(rptr!=lptr)
            {
                ans.push_back(rptr-lptr+1);
            }
            
            if(rptr==s.size()-1)
            {
                break;
            }
            lptr = rptr+1;
            rptr = end[s[lptr]-'a'];
            if(lptr==rptr)
            {
                cout<<s[lptr]<<endl;
                ans.push_back(1);
            }
            if(rptr==s.size()-1 &&lptr!=rptr)
            {
                ans.push_back(rptr-lptr+1);
            }
            
        }
        return ans;
    }
};
