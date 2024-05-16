class Solution {
public:
int m,n;
int dir[4][2]={
    {-1,0},{0,1},{1,0},{0,-1}
};
vector<string> v;
    struct trieNode {
        bool end;
        string word;
        trieNode* child[26];
    };
    trieNode* getNode()
    {
        trieNode* node= new trieNode();
        node->end=false;
        node->word="";
        for(int i=0;i<26;i++)
        node->child[i]=NULL;
        return node;
    }
    void insert(trieNode* root, string &word)
    {
        trieNode* tmp=root;
        char ch;
        for(int i=0;i<word.size();i++)
        {
            ch=word[i];
            if(tmp->child[ch-'a']==NULL)
            tmp->child[ch-'a']=getNode();
            tmp=tmp->child[ch-'a'];
        }
        tmp->word=word;
        tmp->end=true;
    }
    void findTrieWords(vector<vector<char>> &board, int i, int j, trieNode* root)
    {
        if(i<0 || i>=m || j<0 || j>=n)
        return;
        if(board[i][j]=='$' || root->child[board[i][j]-'a']==NULL)
        return;
        root=root->child[board[i][j]-'a'];
        if(root->end==true)
        {
            v.push_back(root->word);
            root->end=false;
        }
        char ch=board[i][j]; int i_,j_;
        board[i][j]='$';
        for(int k=0;k<4;k++)
        {
            i_=i+dir[k][0]; j_=j+dir[k][1];
            findTrieWords(board,i_,j_,root);
        }
        board[i][j]=ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m=board.size(); n=board[0].size();
        trieNode* root=getNode();
        for(auto &w:words)
        {
            insert(root,w);
        }
        char ch;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ch=board[i][j];
                if(root->child[ch-'a']!=NULL)
                findTrieWords(board,i,j,root);
            }
        }
        return v;
    }
};
