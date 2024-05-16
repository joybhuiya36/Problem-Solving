//Heap Approach
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<points.size();i++)
        {
            pq.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],i});
            if(pq.size()>k)
            pq.pop();
        }
        vector<vector<int>> v;
        while(!pq.empty())
        {
            v.emplace_back(points[pq.top().second]);
            pq.pop();
        }
        return v;
    }
};
//Divide and Conquer Approach
class Solution {
public:
    void conq(vector<vector<int>>& pnt, int l, int mid, int r)
    {
        int m=mid-l+1;
        int n=r-mid;
        vector<vector<int>> a,b;
        for(int i=0;i<m;i++)
        a.push_back(pnt[l+i]);
        for(int i=0;i<n;i++)
        b.push_back(pnt[mid+1+i]);
        int i=0,j=0,k=0;
        while(i<m && j<n)
        {
            int x=pow(a[i][0],2)+pow(a[i][1],2);
            int y=pow(b[j][0],2)+pow(b[j][1],2);
            if(x<=y)
            {
                pnt[l+k]=a[i];
                i++;
            }
            else
            {
                pnt[l+k]=b[j];
                j++;
            }
            k++;
        }
        while(i<m)
        {
            pnt[l+k]=a[i];
            i++; k++;
        }
        while(j<n)
        {
            pnt[l+k]=b[j];
            j++; k++;
        }
    }
    void div(vector<vector<int>>& pnt, int l, int r)
    {
        if(l<r)
        {
            int mid=(l+r)/2;
            div(pnt,l,mid);
            div(pnt,mid+1,r);
            conq(pnt,l,mid,r);
        }
    }
    vector<vector<int>> kClosest(vector<vector<int>>& pnt, int k) {
        div(pnt,0,pnt.size()-1);
        pnt.resize(k);
        return pnt;
    }
};
