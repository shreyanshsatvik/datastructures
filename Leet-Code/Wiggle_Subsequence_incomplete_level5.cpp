class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        vector<int> l(nums.size(),2);
        set<int> s(nums.begin(),nums.end());
        
        if(s.size()>2)
        {
            int d = nums[1]-nums[0];
            l[1]=2;

            for(int i=2;i<nums.size();i++)
            {

                for(int j=0;j<i;j++)
                {
                    if(d<0)
                    {
                        //cout<<d<<endl;
                        if(nums[i]>nums[j] && l[i]<l[j]+1)
                        {
                            //cout<<"C1 "<<nums[i]<<"for j "<<nums[j]<<endl;
                            l[i] = l[j] + 1;

                            if(j==i-1)
                            {
                                if(nums[i]>nums[i-1])
                                {
                                    //cout<<"D+"<<endl;
                                    //cout<<nums[i]<<endl;
                                    d = 1;
                                }
                            }

                        }


                    }
                    else if(d>0)
                    {
                        //cout<<d<<endl;
                        if(nums[i]<nums[j] && l[i]<l[j]+1)
                        {
                            //cout<<"C2 "<<nums[i]<<"for j"<<nums[j]<<endl;
                            l[i] = l[j]+1;
                            if(j==i-1)
                            {
                                if(nums[i]<nums[i-1])
                                {
                                    //cout<<nums[i]<<endl;
                                    d = -1;
                                }
                            }

                        }


                    }

                }
            }
        
        
            
            /*
            for(auto i:l)
            {
                cout<<i<<" ";
            }
            */
            int p = *max_element(l.begin(),l.end());

            int q = nums.size()-s.size();




            return p+q;
        }
        else
        {
            return 1;
        }
        
        
        
    }
};
