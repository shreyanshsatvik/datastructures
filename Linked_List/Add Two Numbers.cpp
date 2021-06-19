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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL)
        {
            return NULL;
        }
        if(l1==NULL)
        {
            return l2;
        }
        if(l2==NULL)
        {
            return l1;
        }
        int a = l1->val+l2->val;
        ListNode* ans_node = new ListNode(a%10);
        ans_node->next = addTwoNumbers(l1->next,l2->next);
        if(a>=10)
        {
            ans_node->next = addTwoNumbers(ans_node->next,new ListNode(1));
        }
        return ans_node;
        
        
    }
};
