class TrieNode {
public:
vector<TrieNode*> n;
bool isEnd;
    TrieNode() {
        n.resize(26,NULL);
        isEnd=false;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur=root;
        for(char &c: word)
        {
            if(!cur->n[c-'a'])
            {
                cur->n[c-'a']=new TrieNode();
            }
            cur=cur->n[c-'a'];
        }
        cur->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode* cur=root;
        for(char &c: word)
        {
            if(!cur->n[c-'a'])
            {
                return false;
            }
            cur=cur->n[c-'a'];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur=root;
        for(char &c: prefix)
        {
            if(!cur->n[c-'a'])
            {
                return false;
            }
            cur=cur->n[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
