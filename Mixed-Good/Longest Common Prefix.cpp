class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        string s = "";
        if(arr.size()==1)
        {
            return arr[0];
        }
        sort(arr.begin(),arr.end(),[](auto &s1, auto &s2)
             {
                 return s1.size()<s2.size();
             });
        string con = arr[0];
        for(int i=0;i<con.size();i++)
        {
            char l = con[i];
            for(int j=1;j<arr.size();j++)
            {
                if(arr[j][i]==l)
                {
                    if(j==arr.size()-1)
                    {
                        s += l;
                    }
                }
                else
                {
                    return s;
                }
            }
        }
        return s;
        
    }
};
