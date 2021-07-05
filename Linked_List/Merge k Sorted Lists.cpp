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
    
    ListNode* findmiddle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* head1,ListNode* head2)
    {
        ListNode* merged = new ListNode(-1);
        ListNode* temp = merged;
        
        while(head1 && head2)
        {
            if(head1->val<head2->val)
            {
                temp->next= head1;
                head1 = head1->next;
                temp = temp->next;
            }
            else
            {
                temp->next= head2;
                head2 = head2->next;
                temp = temp->next;
            }
        }
        if(head1)
        {
            temp->next = head1;
            
        }
        if(head2)
        {
            temp->next = head2;
        }
        return merged->next;
    }
    
    ListNode* sortList(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* middle = findmiddle(head);
        ListNode* temp = middle->next;
        middle->next = NULL;
        ListNode* first_half = sortList(head);
        ListNode* second_half = sortList(temp);
        ListNode* merged = merge(first_half,second_half);
        return merged;
        
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
        {
            return NULL;
        }
        ListNode* new_list = new ListNode(-1);
        ListNode* final_list = new_list;
        for(auto i:lists)
        {
            new_list->next = i;
            while(new_list->next)
            {
                new_list= new_list->next;
            }
        }
        final_list =  final_list->next;
        ListNode* ans = sortList(final_list);
        return ans;
    }
    
};
