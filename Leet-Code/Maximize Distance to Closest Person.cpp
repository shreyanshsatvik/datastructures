class Solution {
public:
    void all_occurences(vector<int> &arr,vector<int> nums)
    {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                arr.push_back(i);
            }
        }
    }
    int max(int a,int b)
    {
        if(a>b)
        {
            return a;
        }
        return b;
    }
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int cal = count(seats.begin(),seats.end(),1);
        vector<int> :: iterator it;
        vector<int> pos;
        priority_queue<int> pq;
        if(seats.size()==2)
        {
            return 1;
        }
        
        if(cal==1 && (seats[0]==1|| seats[seats.size()-1]==1))
        {
            return seats.size()-1;
        }
        if(cal==1)
        {
            all_occurences(pos,seats);
            return max(seats.size()-pos[0]-1,pos[0]);
        }
        else if(cal>1)
        {
            all_occurences(pos,seats);
            
            if(seats[0]==0)
            {
            
                pq.push(pos[0]*2);
            }
            if(seats[seats.size()-1]==0)
            {
                pq.push((seats.size()-1-pos[pos.size()-1])*2);
            }
            for(int i=1;i<pos.size();i++)
            {
                pq.push(pos[i]-pos[i-1]);
            }
            
            return pq.top()/2;
        }
        
    
        return 1;
    }
};
