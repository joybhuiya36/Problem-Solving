//Total 4 Approaches
//Two Pointer
class Solution {
public:
    int trap(vector<int>& h) {
        int l=0,r=h.size()-1,lmax=0,rmax=0,trap=0;
        while(l<r)
        {
            if(h[l]<h[r])
            {
                lmax=max(lmax,h[l]);
                trap+=lmax-h[l];
                l++;
            }
            else
            {
                rmax=max(rmax,h[r]);
                trap+=rmax-h[r];
                r--;
            }
        }
        return trap;
    }
};
//Monotonic Stack
class Solution {
public:
    int trap(vector<int>& h) {
        stack<int>stk;
        int n=h.size(),ans=0,width,cur;
        for(int i=0;i<n;i++)
        {
            while(stk.size()>0 && h[stk.top()]<=h[i])
            {
                cur=stk.top();
                stk.pop();
                if(stk.empty()) break;
                width=i-stk.top()-1;
                ans+=(min(h[i],h[stk.top()])-h[cur])*width;
            }
            stk.push(i);
        }
        return ans;
    }
};
//DP
class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size(),mx=0,mx2=0,trap,water=0;
        int lmax[n],rmax[n];
        for(int i=0;i<n;i++)
        {
            mx=max(mx,h[i]);
            lmax[i]=mx;
            mx2=max(mx2,h[n-1-i]);
            rmax[n-1-i]=mx2;
        }
        for(int i=1;i<n-1;i++)
        {
            trap=min(lmax[i-1],rmax[i+1])-h[i];
            if(trap>0)
            water+=trap;
        }
        return water;
    }
};
//Optimized
class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size(),idx=0,mx=0,water=0;
        for(int i=1;i<n;i++)
        {
            if(h[i]>h[idx])
            idx=i;
        }
        for(int i=0;i<idx;i++)
        {
            if(h[i]>mx)
            mx=h[i];
            water+=min(mx,h[idx])-h[i];
        }
        mx=0;
        for(int i=n-1;i>idx;i--)
        {
            if(h[i]>mx)
            mx=h[i];
            water+=min(mx,h[idx])-h[i];
        }
        return water;
    }
};
