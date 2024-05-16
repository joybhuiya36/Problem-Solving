/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector< vector<int> > v;
        if(!root) return v;
        queue<Node*> q;
        q.push(root);
        int i=0;
        while(!q.empty())
        {
            int n=q.size();
            v.push_back({});
            while(n--)
            {
                root=q.front();
                q.pop();
                v[i].push_back(root->val);
                for(int i=0;i<root->children.size();i++)
                {
                    q.push(root->children[i]);
                }
            }
            i++;
        }
        return v;
    }
};
