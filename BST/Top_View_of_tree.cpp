void topView(Node * root) {
        map<int,int> root_list;
        queue<pair<int,Node*>> que;
        //visited<bool> v;
        //que.push(root);
        root_list.insert({0,root->data});
        int l=0;
        que.push(make_pair(0,root));
        while(!que.empty())
        {
            l = que.front().first;
            Node* a = que.front().second;
            que.pop();
            if(a->left!=NULL)
            {
                int k = l-1;
                if(root_list.find(k)==root_list.end())
                {
                    root_list.insert({k,a->left->data});
                }
                
                                                       
                que.push(make_pair(k,a->left));
            }
            if(a->right!=NULL)
            {
                int k = l+1;
                if(root_list.find(k)==root_list.end())
                {
                    root_list.insert({k,a->right->data});
                }
                
                que.push(make_pair(k,a->right));
    
            }
            
        }
        map<int,int>::iterator i;
        for(i=root_list.begin();i!=root_list.end();i++)
        {
            cout<<i->second<<" "; 
        }
        
    

    }  
  
      


}; //End of Solution

