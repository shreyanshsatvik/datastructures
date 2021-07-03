class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        if(head==NULL)
        {
            return head;
        }
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            
        }
        return slow;
        
    }
};
