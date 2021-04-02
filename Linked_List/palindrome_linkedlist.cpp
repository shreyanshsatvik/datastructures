class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        ListNode* new_head = head;
        while(head!=NULL)
        {
            arr.push_back(head->val);
            head = head->next;
        }
        vector<int> arr1(arr.begin(),arr.end());
        reverse(arr.begin(),arr.end());
        if(arr==arr1)
        {
            return true;
        }
        return false;
    }
};
