class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        map<int,int> mp;
        for(auto i:nums)
        {
            mp[i]++;
        }
        bool flag = true;
        int x = mp.begin()->first;
        int maxx = 0;
        int count = 0;
        
        for(auto i=mp.begin();i!=mp.end();i++)
        {
            
            if(i->first-x==1 && flag==true)
            {
                count = 1;
                x = i->first;
                flag = false;
            }
            else if(i->first-x!=1 && flag == false)
            {
                x= i->first;
                count = 0;
                flag = true;
            
            }
            else if(i->first-x==1 && flag == false)
            {
                x = i->first;
                count++;
            }
            else
            {
                x = i->first;
            }
            maxx = max(maxx,count);
        
            
            
        }
        return maxx+1;
    }
};
