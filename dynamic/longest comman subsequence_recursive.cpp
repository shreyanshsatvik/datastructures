class Solution{
    public:
        int lcs(string s,string s1,string s2)
        {
            if(s1.size()==0|| s2.size()==0)
            {
                return s.size();
            }
            
            
            
        }
        int lcs(int x, int y, string s1, string s2){
        
        // your code here
        if(s1.size()==0||s2.size()==0)
        {
            return 0;
        }
        if(s1[x-1]==s2[y-1])
        {
            return 1+lcs(x-1,y-1,s1.substr(0,x-1),s2.substr(0,y-1));
        }
        else
        {
            return max(lcs(x-1,y,s1.substr(0,x-1),s2),lcs(x,y-1,s1,s2.substr(0,y-1)));
            
        }
        
        
        
        
        
    }
};
