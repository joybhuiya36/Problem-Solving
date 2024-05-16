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

//Recursive way
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if(!root)
        return ans;
        dfs(root, ans);
        return ans;
    }
    void dfs(Node* root, vector<int> &ans)
    {
        ans.push_back(root->val);
        for(int i=0;i<root->children.size();i++)
        {
            dfs(root->children[i],ans);
        }
    }
};

//Iterative way
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        stack<Node*> s;
        if(!root)
        return ans;
        s.push(root);
        while(!s.empty())
        {
            Node* ind= s.top();
            ans.push_back(ind->val);
            s.pop();
            for(int i=ind->children.size()-1;i>=0;--i)
            {
                s.push(ind->children[i]);
            }
        }
        return ans;
    }
};
