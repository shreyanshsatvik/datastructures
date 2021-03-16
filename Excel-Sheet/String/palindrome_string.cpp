class Solution{
public:	
	
	
	int isPlaindrome(string S)
	{
	    // Your code goes here
	    vector<char> arr;
	    for(int i=0;i<S.size();i++)
        {
            arr.push_back(S[i]);
        }	    
	    reverse(arr.begin(),arr.end());
	    string s ="";
	    for(int i=0;i<S.size();i++)
        {
            s = s+arr[i];
        }
	    if(s==S)
	    {
	        return 1;
	    }
	    else
	    {
	        return 0;
	    }
	    
	    
	    
	}

};
