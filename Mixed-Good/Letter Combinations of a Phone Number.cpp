class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> two = {"a","b","c"};
        vector<string> three = {"d","e","f"};
        vector<string> four = {"g","h","i"};
        vector<string> five = {"j","k","l"};
        vector<string> six = {"m","n","o"};
        vector<string> seven = {"p","q","r","s"};
        vector<string> eight = {"t","u","v"};
        vector<string> nine = {"w","x","y","z"};
        
        map<char,vector<string>> mp;
        mp.insert(make_pair('2',two));
        mp.insert(make_pair('3',three));
        mp.insert(make_pair('4',four));
        mp.insert(make_pair('5',five));
        mp.insert(make_pair('6',six));
        mp.insert(make_pair('7',seven));
        mp.insert(make_pair('8',eight));
        mp.insert(make_pair('9',nine));
        
        vector<string> ans={""};
        if(digits.size()==0)
        {
            vector<string> ans1;
            return ans1;
        }
        if(digits.size()==1)
        {
            char k = digits[0];
            return mp[k];
        }
        for(int i=0;i<digits.size();i++)
        {
            vector<string> temp;
            for(int j=0;j<mp[digits[i]].size();j++)
            {
                for(int k=0;k<ans.size();k++)
                {
                    temp.push_back(ans[k]+mp[digits[i]][j]);
                }
                
            }
            ans = temp;
        }
        return ans;
    }
};
