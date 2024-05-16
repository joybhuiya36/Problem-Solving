/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        unordered_map<Node*,int> mp;
        vector<Node*> v;
        Node* root=new Node(head->val);
        Node* cur=head->next;
        Node* ptr=root;
        int i=0;
        mp[head]=i++;
        while(cur!=NULL)
        {
            Node* newb=new Node(cur->val);
            ptr->next=newb;
            v.push_back(ptr);
            mp[cur]=i++;
            ptr=ptr->next;
            cur=cur->next;
        }
        v.push_back(ptr);
        mp[ptr]=i;
        cur=head;
        for(int j=0;cur!=NULL;j++)
        {
            if(cur->random!=NULL)
            v[j]->random=v[mp[cur->random]];
            cur=cur->next;
        }
        // v[1]->random=v[0];
        // v[2]->random=v[4];
        // v[3]->random=v[2];
        // v[4]->random=v[0];
        // ptr=root;
        // while(ptr!=NULL)
        // {
        //     cout<<ptr->val<<"->";
        //     ptr=ptr->next;
        // }
        // cout<<"NULL"<<endl;
        return root;
    }
};
