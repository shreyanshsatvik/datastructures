class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        
        int n = candyType.size();
        set<int> x;
        for (int i=0;i<candyType.size();i++)
        {
            x.insert(candyType[i]);
        }
        int k = x.size();
        
        return min(n/2,k);
        
    }
};
