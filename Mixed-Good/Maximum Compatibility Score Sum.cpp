
class Solution {
public:
    int ans = 0;
    void score(vector<vector<int>>& students, vector<vector<int>>& mentors,int start,vector<bool> &visited,int val)
    {
        if(start==mentors.size())
        {
            ans = max(ans,val);
            return;
        }
        for(int i=0;i<mentors.size();i++)
        {
            if(visited[i])continue;
            visited[i] = true;
            int s = 0;
            for(int j=0;j<mentors[i].size();j++)
            {
                if(mentors[i][j]==students[start][j])
                {
                    s++;
                }
            }
            score(students,mentors,start+1,visited,val+s);
            visited[i] = false;
            
        }
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
    
        vector<bool> visited(mentors.size(),false);
        score(students,mentors,0,visited,0);
        
        return ans;
        
        
        
        
    }
};
