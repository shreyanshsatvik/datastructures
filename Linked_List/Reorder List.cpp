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
    
    void reorderList(ListNode* head) {
        if(head->next)
        {
            ListNode* slow = head;
            ListNode* fast = head;
            ListNode* prev = NULL;
            while(fast && fast->next)
            {
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            prev->next = NULL;
            stack<ListNode*> st;
            while(slow)
            {
                st.push(slow);
                slow = slow->next;
                st.top()->next = NULL;
            }
            ListNode* nnhead = head;

            while(!st.empty())
            {
                ListNode* temp = nnhead->next;
                nnhead->next = st.top();
                st.pop();


                if(temp==NULL && !st.empty())
                {

                    temp = st.top();
                    st.pop();

                }
                nnhead->next->next = temp;

                nnhead = temp;

            }
        }   
    }
};
