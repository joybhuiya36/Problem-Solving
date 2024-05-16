class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<int,Node*> mp;
        queue<Node*> q;
        q.push(node);
        Node* root=new Node(node->val);
        mp[root->val]=root;
        Node *cur,*cur2;
        while(!q.empty())
        {
            cur=q.front();
            cur2=mp[cur->val];
            q.pop();
            for(int i=0;i<cur->neighbors.size();i++)
            {
                if(!mp.count(cur->neighbors[i]->val))
                {
                    Node* child=new Node(cur->neighbors[i]->val);
                    mp[cur->neighbors[i]->val]=child;
                    q.push(cur->neighbors[i]);
                    cur2->neighbors.push_back(child);
                }
                else
                cur2->neighbors.push_back(mp[cur->neighbors[i]->val]);
                
            }
        }
        return root;
    }
};
//dfs recursion
class Solution {
public:
    unordered_map<Node*,Node*>m;
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;
        if(m.count(node))
            return m[node];
        m[node]=new Node(node->val);
        for(auto &e:node->neighbors){
            //cout << ans->val <<":->" <<e->val<<endl;
            m[node]->neighbors.push_back(cloneGraph(e));
        }
        return m[node];
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

