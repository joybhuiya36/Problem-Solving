/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        Node* cur,*pre;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                cur=q.front();
                q.pop();
                if(cur->left)
                {
                    q.push(cur->left);
                    q.push(cur->right);
                    if(pre!=NULL)
                    pre->next=cur->left;
                    cur->left->next=cur->right;
                    pre=cur->right;
                }
            }
            pre=NULL;
        }
        return root;
    }
};
//New Approach
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)return root;
        if(root->left)root->left->next=root->right;
        if(root->next && root->right)root->right->next=root->next->left;
        connect(root->left);
        connect(root->right);
        return root;
        
    }
};
