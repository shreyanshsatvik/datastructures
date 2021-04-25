struct node *reverse (struct node *head, int k)
    { 
        if(!head)
        {
            return NULL;
        }
        node* current = head;
        node* next = NULL;
        node* prev = NULL;
        int count = 0;
 
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
 
    /* next is now a pointer to (k+1)th node
    Recursively call for the list starting from current.
    And make rest of the list as next of first node */
    if (next != NULL)
        head->next = reverse(next, k);
 
    /* prev is new head of the input list */
    return prev;
}
