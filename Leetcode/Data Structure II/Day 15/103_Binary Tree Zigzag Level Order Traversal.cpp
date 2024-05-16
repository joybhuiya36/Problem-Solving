class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        int n,lvl=1;
        while(!q.empty())
        {
            n=q.size();
            vector<int> v;
            while(n--)
            {
                root=q.front();
                q.pop();
                v.push_back(root->val);
                if(root->left)
                q.push(root->left);
                if(root->right)
                q.push(root->right);
            }
            if(lvl%2==0)
            reverse(v.begin(),v.end());
            ans.push_back(v);
            lvl++;
        }
        return ans;
    }
};
//More optimal without reversing the v
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return {};
        queue<TreeNode*>q;
        q.push(root);
        int count = 0;
        while(!q.empty())
        {
            int size = q.size();
            count++;
            vector<int>v(size);
            for(int i=0;i<size;i++)
            {
                TreeNode*node;
                node = q.front();
                q.pop();
                int index = count%2!=0?i:size-i-1;
                v[index] = node->val;
                
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
                
                
            }
            ans.push_back(v);
        }
        return ans;
     }
};
