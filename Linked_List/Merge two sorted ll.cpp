/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        vector<int> arr;
        if(l1==NULL && l2==NULL)
        {
            return l1;
        }
        if(l1==NULL)
        {
            return l2;
        }
        if(l2==NULL)
        {
            return l1;
        }
        while(l1)
        {
            arr.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2)
        {
            arr.push_back(l2->val);
            l2 = l2->next;
        }
        sort(arr.begin(),arr.end());
        ListNode* new_list = new ListNode(arr[0]);
        ListNode* ans = new_list;
        for(int i=1;i<arr.size();i++)
        {
            ListNode* nn = new ListNode(arr[i]);
            new_list->next = nn;
            new_list = new_list->next;
        }
        return ans;
    }
};
