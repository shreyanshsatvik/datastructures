class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        
        words[0] = words[0]+"#";
        string max = words[0];
        vector<string> :: iterator it;
        for(int i=1;i<words.size();i++)
        {
            words[i] = words[i]+"#";
            if(words[i].size()>max.size())
            {
                max = words[i];
                
            }
        }
        words.erase(remove(words.begin(), words.end(), max), words.end());
        for(int i=0;i<words.size();i++)
        {
            if(max.find(words[i])==string::npos)
            {
                max += words[i];
            }
            
        }
        return max.size();
        
        
        
        
    }
};
