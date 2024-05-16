/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        int n;
        string s;
        s+=to_string(root->val);
        while(!q.empty())
        {
            n=q.size();
            while(n--)
            {
                root=q.front();
                q.pop();
                if(root->left)
                {
                    q.push(root->left);
                    s+=','+to_string(root->left->val);
                }
                else s+=",null";
                if(root->right)
                {
                    q.push(root->right);
                    s+=','+to_string(root->right->val);
                }
                else s+=",null";
            }
        }
        return s;
    }
    int getNum(string &data, int &idx)
    {
        string s;
        while(idx<data.length() && data[idx]!=',')
        {
            s+=data[idx];
            idx++;
        }
        idx++;
        return stoi(s);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0) return NULL;
        int idx=0;
        queue<TreeNode*> q;
        TreeNode* root=new TreeNode(getNum(data,idx));
        q.push(root);
        while(!q.empty())
        {
            TreeNode* cur=q.front();
            q.pop();
            if(data[idx]=='n') idx+=5;
            else
            {
                cur->left=new TreeNode(getNum(data,idx));
                q.push(cur->left);
            }
            if(data[idx]=='n') idx+=5;
            else
            {
                cur->right=new TreeNode(getNum(data,idx));
                q.push(cur->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
