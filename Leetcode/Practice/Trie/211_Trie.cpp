class TrieNode {
public:
    bool isEnd;
    unordered_map<char,TrieNode*> mp;
    TrieNode() {
        isEnd=false;
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur=root;
        for(char &c:word)
        {
            if(!cur->mp.count(c))
            {
                TrieNode* node=new TrieNode();
                cur->mp[c]=node;
                cur->mp['.']=node;
            }
            cur=cur->mp[c];
        }
        cur->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode* cur=root;
        for(char &c:word)
        {
            if(!cur->mp.count(c))
            return false;
            cur=cur->mp[c];
        }
        return cur->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
