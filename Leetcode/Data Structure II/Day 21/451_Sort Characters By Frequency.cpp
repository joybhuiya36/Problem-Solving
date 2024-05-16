class Solution {
public:
    string frequencySort(string s) {
        if(s.length()<3) return s;
        int arr[123]={0};
        priority_queue<pair<int,int>>pq;
        for(char &c:s)
        arr[c]++;
        for(int i=48;i<123;i++)
        {
            if(arr[i]>0)
            pq.push({arr[i],i});
        }
        string str;
        int n;
        while(!pq.empty())
        {
            n=pq.top().first;
            while(n--)
            str+=pq.top().second;
            pq.pop();
        }
        return str;
    }
};
