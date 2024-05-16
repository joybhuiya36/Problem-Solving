//Josephus Problem
class Solution {
public:
int Josephus(int n, int k)
{
    if(n==1)
    return 0;
    return (Josephus(n-1,k)+k)%n;
}
    int findTheWinner(int n, int k) {
        return Josephus(n,k)+1;
    }
};
//index erase from vector approach
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v;
        for(int i=1;i<=n;i++)
        v.push_back(i);
        int idx=0, node;
        while(n>1)
        {
            node=(k-1+idx)%n;
            v.erase(v.begin()+node);
            idx=node;
            n--;
        }
        return v[0];
    }
};
//Queue pop and push
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1;i<=n;i++)
        q.push(i);
        int count;
        while(q.size()!=1)
        {
            count=1;
            while(count!=k)
            {
                q.push(q.front());
                q.pop();
                count++;
            }
            q.pop();
        }
        return q.front();
    }
};
