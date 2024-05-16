//Other Solution
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        
        queue<Node*> q;
        q.push(root);
        stack<Node*> st;

        while(q.size())
        {
            int size = q.size();
            Node* prev = NULL;
            
            while(size--)
            {
                Node* curr = q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                st.push(curr);
            }

            while(st.size())
            {
                st.top()->next = prev;
                prev = st.top();
                st.pop();
            }
        }

        return root;
    }
};
//My Solution
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        Node *cur,*temp;
        queue<Node*> q;
        q.push(root);
        while(q.size())
        {
            int n=q.size();
            while(n--)
            {
                cur=q.front();
                q.pop();
                if(cur->left)
                {
                    q.emplace(cur->left);
                    if(cur->right)
                    cur->left->next=cur->right;
                    else if(cur->next)
                    {
                        temp=cur->next;
                        while(temp && temp->left==NULL && temp->right==NULL)
                        {
                            q.pop();
                            n--;
                            temp=temp->next;
                        }
                        if(temp)
                        {
                            if(temp->left)
                            cur->left->next=temp->left;
                            else if(temp->right)
                            cur->left->next=temp->right;
                        }
                    }
                }
                if(cur->right)
                {
                    q.emplace(cur->right);
                    if(cur->next)
                    {
                        temp=cur->next;
                        while(temp && temp->left==NULL && temp->right==NULL)
                        {
                            q.pop();
                            n--;
                            temp=temp->next;
                        }
                        if(temp)
                        {
                            if(temp->left)
                            cur->right->next=temp->left;
                            else if(temp->right)
                            cur->right->next=temp->right;
                        }
                    }
                }
            }
        }
        return root;

    }
};
