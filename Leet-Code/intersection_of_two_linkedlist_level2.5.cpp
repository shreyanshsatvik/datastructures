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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode*> arr1;
        ListNode* new_node = NULL;
        while(headA!=NULL)
        {
            arr1.push_back(headA);
            headA = headA->next;
        }
        vector<ListNode*> arr2;
        while(headB!=NULL)
        {
            arr2.push_back(headB);
            headB = headB->next;
        }
        
        for(int i=0;i<arr1.size();i++)
        {
            if(find(arr2.begin(),arr2.end(),arr1[i])!=arr2.end())
            {
                new_node = arr1[i];
                break;
            }
        }
        
        
        return new_node;
        
        
        
    }
};
