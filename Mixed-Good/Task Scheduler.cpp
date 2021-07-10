class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> arr;
        int max_count = 0;
        set<int> ss(tasks.begin(),tasks.end());
        for(auto e : ss)
        {
            int c = count(tasks.begin(),tasks.end(),e);
            arr.push_back(c);
            max_count = max(c,max_count);
        }
        
        int ans = (max_count-1)*(n+1);
        for(auto e : arr)
        {
            if(e == max_count)
                ans++;
        }
        
        return max((int)tasks.size(), ans);
    }
};
