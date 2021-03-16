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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* new_head = head;
        int l=k;
        k = k-1;
        ListNode* pprev = NULL;
        
        while(k>0 && new_head->next!=NULL)
        {
            pprev = new_head;
            new_head = new_head->next;
            k = k-1;
        
        }
        
    
        ListNode* nnhead = head;
        int i=1;
        while(nnhead->next!=NULL)
        {
            nnhead = nnhead->next;
            i++;
        }
        ListNode* nhead = head;
        ListNode* prev = NULL;
        
        int j = i-l;

        cout<<l<<endl;
        
        
        if(j>=0)
        {
            if(j>0)
            {
        
                while(j>0 && nhead->next!=NULL)
                {
                    prev = nhead;
                    nhead = nhead->next;
                    j = j-1;
                }
                if(pprev!=NULL)
                {
                    pprev->next = nhead;
                }
                else
                {
                    head = nhead;
                }
                if(prev!=NULL )
                {
                    prev->next = new_head;
                }
                ListNode* temp = new_head->next;
                new_head->next = nhead->next;
                nhead->next = temp;
                
            }
            else
            {
                while(j>0 && nhead->next!=NULL)
                {
                    prev = nhead;
                    nhead = nhead->next;
                    j = j-1;
                }
                if(pprev!=NULL)
                {
                    pprev->next = nhead;
                }
                else
                {
                    head = nhead;
                }
                if(prev!=NULL )
                {
                    prev->next = new_head;
                }
                ListNode* temp = new_head->next;
                new_head->next = nhead->next;
                nhead->next = temp;
                head = new_head;    
            }
            
        }
        
        return head;
        
    
        
        
        
        
    }
};
