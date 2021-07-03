
class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        if(head->next==NULL)
        {
            return head;
        }
        ListNode* new_head = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return new_head;
    }
        
    ListNode* reverseKGroup(ListNode* head, int k) {
    
        
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        int count = 0;
        while(count<k && current)
        {
            
            next = current->next;
            current->next= prev;
            prev = current;
            current = next;
            count++;
        }
        if(count<k)
        {
            return reverse(prev);
        }
        if(next)
        {
            head->next = reverseKGroup(next,k);
        }
        return prev;
    }
};
