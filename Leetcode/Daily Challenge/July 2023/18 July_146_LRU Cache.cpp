//List
class LRUCache {
public:
int n,idx;
pair<list<int>::iterator,int> cur;
list<int> dll;
unordered_map<int,pair<list<int>::iterator,int>> mp;
    LRUCache(int capacity) {
        n=capacity;
    }
    
    int get(int key) {
        if(mp.count(key))
        {
            cur=mp[key];
            dll.erase(cur.first);
            dll.push_front(key);
            mp[key].first=dll.begin();
            return cur.second;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key))
        {
            cur=mp[key];
            dll.erase(cur.first);
            dll.push_front(key);
            mp[key]={dll.begin(),value};
        }
        else
        {
            dll.push_front(key);
            mp[key]={dll.begin(),value};
            n--;
            if(n<0)
            {
                idx=dll.back();
                dll.pop_back();
                mp.erase(idx);
                n++;
            }
        }
    }
};

//Doubly Linked List (Online Compiler Problem)
class node {
public:
    int val;
    node* pre;
    node* nxt;
    node(int x)
    {
        val=x;
        pre=NULL;
        nxt=NULL;
    }
};
class LRUCache {
public:
node* head=new node(-1);
node* tail=new node(-1);
node *cur,*tmp;
int n;
unordered_map<int,node*> mp;
    LRUCache(int capacity) {
        n=capacity;
        head->nxt=tail;
        tail->pre=head;
    }
    node* old_rmv(int key)
    {
        cur=mp[key];
        tmp=cur;
        tmp->pre->nxt=cur->nxt;
        cur->nxt->pre=tmp->pre;
        return cur;
    }
    void add_tail(node* cur)
    {
        tmp=tail;
        cur->pre=tail->pre;
        cur->pre->nxt=cur;
        cur->nxt=tail;
        tail->pre=cur;
    }
    int get(int key) {
        cout<<"outter "<<key<<endl;
        if(mp.count(key) && mp[key]!=NULL)
        {
            cout<<"inner "<<key<<endl<<endl;
            cur=old_rmv(key);
            add_tail(cur);
            return cur->val;
        }
        else
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key) && mp[key]!=NULL)
        {
            
            cur=mp[key];
            tmp=cur;
            tmp->pre->nxt=cur->nxt;
            cur->nxt->pre=tmp->pre;
            
            tmp=tail;
            cur->pre=tail->pre;
            cur->pre->nxt=cur;
            cur->nxt=tail;
            tail->pre=cur;

            cur->val=value;
        }
        else
        {
            if(n==0)
            {
                tmp=cur=head->nxt;
                tmp->pre->nxt=cur->nxt;
                cur->nxt->pre=tmp->pre;

                mp[cur->val]=nullptr;
                cur=new node(value);
                mp[key]=cur;
                cur=mp[key];

                tmp=tail;
                cur->pre=tail->pre;
                cur->pre->nxt=cur;
                cur->nxt=tail;
                tail->pre=cur;
            }
            else
            {
                cur=new node(value);
                mp[key]=cur;
                tmp=tail;
                cur->pre=tail->pre;
                cur->pre->nxt=cur;
                cur->nxt=tail;
                tail->pre=cur;
                n--;
            }
        }
    }
};

