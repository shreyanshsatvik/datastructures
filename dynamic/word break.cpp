class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
        vector<bool> arr(s.size()+1,false);
        arr[0] = true;
        for(int i=1;i<s.size()+1;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(find(dict.begin(),dict.end(),s.substr(j,i-j))!=dict.end())
                {
                    if(arr[j])
                    {
                        arr[i] = true;
                        break;
                    }
                }
            }
        }
        return arr[s.size()];
    }
};
