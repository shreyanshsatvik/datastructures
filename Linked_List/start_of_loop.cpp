/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*,int> mp;
        if(head==NULL)
        {
            return NULL;
        }
        ListNode* slow = head;
        while(slow)
        {
            
            if(slow->val>100000)
            {
                return slow;
            }
            slow->val += 1000000;
            slow = slow->next;
        }
        return NULL;
    }
};
