class Solution {
public:
    vector<vector<int>> ans;
    void recur(vector<int> check,int init,int k, int n)
    {
        if(n<0 || check.size()>k )
        {
            return;
        }
        if(n==0 && check.size()==k)
        {
            ans.push_back(check);
            return;
        }
        for(int i=init;i<=9;i++)
        {
            check.push_back(i);
            recur(check,i+1,k,n-i);
            check.pop_back();
        }
       
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> check;
        recur(check,1,k,n);
        return ans;
    }
};
