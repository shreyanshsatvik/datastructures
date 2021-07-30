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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
        {
            return NULL;
        }
       
        int size = 0;
        ListNode* head1 = head;
        ListNode* prev = NULL;
        while(head1)
        {
            size++;
            prev = head1;
            head1= head1->next;
        }
        if(size==1 || k==0)
        {
            return head;
        }
        
        k= size-(k%size);
        if(k>=size)
        {
            return head;
        }
        ListNode* temp = head;
        while(k-1>0)
        {
            temp = temp->next;
            k--;
            
            
        }
        ListNode *headd = temp->next;
        temp->next = NULL;
        prev->next = head;
        return headd;
        
        
    }
};
