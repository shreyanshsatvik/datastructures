class Solution {
public:

    bool is_substr(string s1,string s2)
    {
        int m = 0;
        int n=0;
        while(m<s1.size() && n<s2.size())
        {
            if(s1[m]==s2[n])
            {
                m++;
                n++;
            }
            else
            {
                n++;
            }
        }
        if(s1.size()==m)
        {
            return true;
        }
        return false;
        
    }
    int longestStrChain(vector<string>& words) {
        
        
        sort(words.begin(),words.end(),[](auto &left,auto&right){
            return left.size()<right.size();
        });
        vector<int> arr(words.size(),1);
        int n = words.size();
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(words[i].size()==words[j].size()+1)
                {
                    if(is_substr(words[j],words[i]) && arr[i]<arr[j]+1)
                    {
                        arr[i] = arr[j]+1;
                    }
                }
            }
        }
       
        return *max_element(arr.begin(),arr.end());
    }
 
};
