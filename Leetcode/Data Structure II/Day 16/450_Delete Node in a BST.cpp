//Optimized solution
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val==key){
            if(!root->right){
                TreeNode*left=root->left;
                delete root;
                return left;
            }
            else if(!root->left){
                TreeNode*right=root->right;
                delete root;
                return right;
            }
            else{
                TreeNode*right=root->right;
                while(right->left){
                    right=right->left;
                }
                swap(root->val,right->val);
            }
        }
        root->left=deleteNode(root->left,key);
        root->right=deleteNode(root->right,key);
        return root;
    }
};
//My solution
class Solution {
public:
TreeNode* parent=NULL;
    TreeNode* update(TreeNode* node)
    {
        if(node->left==NULL)
        {
            if(parent!=NULL)
            {
                if(parent->val>node->val)
                parent->left=node->right;
                else
                parent->right=node->right;
            }
            node=node->right;
            return node;
        }
        TreeNode* temp=node->right;
        if(parent!=NULL)
        {
            if(parent->val>node->val)
            parent->left=node->left;
            else
            parent->right=node->left;
        }
        node=node->left;
        TreeNode* cur=node;
        while(cur->right!=NULL)
        cur=cur->right;
        cur->right=temp;
        return node;
    }
    TreeNode* search(TreeNode* root, int &key, TreeNode* &pre)
    {
        if(root==NULL) return NULL;
        if(root->val==key)
        {
            parent=pre;
            return root;
        }
        else if(root->val>key)
        return search(root->left,key,root);
        else
        return search(root->right,key,root);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        TreeNode* node=search(root,key,parent);
        if(node==NULL)
        return root;
        TreeNode* updateNode=update(node);
        if(root->val==key)
        root=updateNode;
        return root;
    }
};
