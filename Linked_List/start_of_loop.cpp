class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head!=NULL)
        {
            ListNode* new_node = head;
            vector<ListNode*> arr;
            arr.push_back(new_node);
            while(new_node->next!=NULL)
            {
                if(binary_search(arr.begin(),arr.end(),new_node->next))
                {

                    return new_node->next;
                }
                new_node = new_node->next;
                arr.push_back(new_node);
            }
        }
        return NULL;
        
        
        
        
    }
};
