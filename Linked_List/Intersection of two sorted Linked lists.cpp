Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    vector<int> arr;
    vector<int> arr1;
    while(head1!=NULL)
    {
        arr.push_back(head1->data);
        head1= head1->next;
    }
    while(head2!=NULL)
    {
        arr1.push_back(head2->data);
        head2= head2->next;
    }
    
    Node* new_node = new Node(-1);
    Node* second_node = new_node;
    for(int i=0;i<arr.size();i++)
    {
        for(int j = 0;j<arr1.size();j++)
        {
            if(arr[i]==arr1[j])
            {
                Node* nn_node = new Node(arr[i]);
                new_node->next = nn_node;
                new_node = new_node->next;
                break;
            }
        }
    }
    return second_node->next;
}
