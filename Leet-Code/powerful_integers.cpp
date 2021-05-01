class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        
        set<int> arr;
        if(bound<=1)
        {
            vector<int> arr;
            return arr;
        }
        if(x>1 && y>1)
        {
            for(int i=1;i<=bound;i*= x)
            {
                for(int j=1;i+j<=bound; j*=y)
                {
                    arr.insert(i+j);
                }
            }
            vector<int> arr1(arr.begin(),arr.end());
            return arr1;
        }
        else
        {
            if(x==1 && y==1)
            {
                arr.insert(2);
            }
            else if(x==1)
            {
                for(int i=1;i+1<=bound;i*=y)
                {
                    arr.insert(i+1);
                }
            }
            else if(y==1)
            {
                for(int i=1;i+1<=bound;i*=x)
                {
                    arr.insert(i+1);
                }
            }
            
             vector<int> arr1(arr.begin(),arr.end());
            return arr1;
        }
        
        
        
    }
};
