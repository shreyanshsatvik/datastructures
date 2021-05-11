class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        int n = target.size();
        while(*max_element(target.begin(),target.end())>=1)
        {
            sort(target.begin(),target.end());
            int sum = accumulate(target.begin(),target.end()-1,0);
            int maxx = target[n-1];
            if(maxx-sum<=0)
            {
                return false;
            }
            target[n-1] = maxx - sum;
            if(count(target.begin(),target.end(),1)==n)
            {
                return true;
            }
        }
        
        return false;
    }
};
