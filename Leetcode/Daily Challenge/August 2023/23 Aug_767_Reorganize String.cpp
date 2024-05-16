class Solution {
    typedef pair<int,int> P;
public:
    string reorganizeString(string s) {
        int mp[26]={0};
        int n=s.length();
        for(int i=0;i<n;i++)
        mp[s[i]-'a']++;

        priority_queue<P,vector<P>> pq;
        for(int i=0;i<26;i++)
        {
            if(mp[i]>(n+1)/2)
            return "";
            if(mp[i]>0)
            pq.push({mp[i],i});
        }
        P p1,p2;
        string str;
        while(pq.size()>=2)
        {
            p1=pq.top();
            pq.pop();

            p2=pq.top();
            pq.pop();

            str+=('a'+p1.second);
            str+=('a'+p2.second);
            if(p1.first-1>0)
            pq.push({p1.first-1,p1.second});
            if(p2.first-1>0)
            pq.push({p2.first-1,p2.second});
        }
        if(!pq.empty())
        str+=(pq.top().second+'a');
        return str;
    }
};
