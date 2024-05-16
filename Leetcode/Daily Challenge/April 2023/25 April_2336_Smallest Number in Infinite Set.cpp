class SmallestInfiniteSet {
public:
vector<bool> checker;
priority_queue<int, vector<int>, greater<int>> pq;
int n=1,cur;
    SmallestInfiniteSet() {
        checker.resize(1001,true);
    }
    
    int popSmallest() {
        if(pq.size()==0 || pq.top()>n)
        cur=n++;
        else
        {
            cur=pq.top();
            pq.pop();
        }
        checker[cur]=false;
        return cur;
    }
    
    void addBack(int num) {
        if(checker[num]==false)
        {
            checker[num]=true;
            pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
