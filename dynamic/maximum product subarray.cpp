class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int max_so_far = arr[0];
        int min_so_far = arr[0];
        int current_ans = arr[0];
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]<0)
            {
                swap(max_so_far,min_so_far);
            }
            max_so_far = max(max_so_far*arr[i],arr[i]);
            min_so_far = min(min_so_far*arr[i],arr[i]);
            current_ans = max(current_ans,max_so_far);
        }
        return current_ans;
        
    }
};
