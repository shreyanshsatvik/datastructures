class Solution {
public:
    string convert(string str)
    {
        if(str.size()==1)
        {
            string s =to_string(1)+str[0];
            return s;
        }
        string s ="";
        
        int count = 1;
        for(int i=1;i<str.size();i++)
        {
            if(str[i]!=str[i-1])
            {
                s += to_string(count)+str[i-1];
                count = 0;
            }
            if(i==str.size()-1)
            {
                if(str[i]==str[i-1])
                {
                    s+= to_string(count+1)+str[i];
                }
                else
                {
                    s+= to_string(1)+str[i];
                }
            }
            count++;
        }
        return s;
    }
    
    string countAndSay(int n) {
        
        vector<string> arr(n);
        arr[0] = to_string(1);
        for(int i=1;i<n;i++)
        {
            arr[i] = convert(arr[i-1]);
        }
        return arr[n-1];
        
    }
};




