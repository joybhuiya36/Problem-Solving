    ListNode* rev(ListNode* root)
    {
        if(root==NULL || root->next==NULL)
        return root;
        ListNode* tmp=rev(root->next);
        root->next->next=root;
        root->next=NULL;
        return tmp;
    }
