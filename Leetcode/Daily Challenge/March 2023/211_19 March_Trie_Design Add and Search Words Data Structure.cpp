//Trie_Design Add and Search Words Data Structure
class TrieNode {
public:
    bool end;
    unordered_map<char,TrieNode*> mp;
    TrieNode() {
        end=false;
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
            if(!cur->mp[c])
            cur->mp[c]=new TrieNode();
            cur=cur->mp[c];
        }
        cur->end=true;
    }
    bool searchHelper(TrieNode* cur, string &word, int index)
    {
        if(index==word.length())
        return cur->end;
        if(word[index]=='.')
        {
            for(auto &it:cur->mp)
            {
                if(it.second && searchHelper(it.second,word,index+1))
                return true;
            }
            return false;
        }
        else
        {
            if(!cur->mp[word[index]])
            return false;
            return searchHelper(cur->mp[word[index]],word,index+1);
        }
    }
    bool search(string word) {
        return searchHelper(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
