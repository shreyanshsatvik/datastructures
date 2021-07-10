class Solution {
public:
    int countTriples(int n) {
        if(n<=4)
        {
            return 0;
        }
        //vector<bool> arr(n,false);
        int count =0;
        for(int i=3;i<=n-1;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                int x = sqrt(i*i+j*j);
                int y = i*i+j*j;
                if(y == x*x && x<=n)
                {
                    //cout<<i<<" "<<j<<" "<<x<<endl;
                    count++;
                }
            }
        }
        return count*2;
        
    }
};
