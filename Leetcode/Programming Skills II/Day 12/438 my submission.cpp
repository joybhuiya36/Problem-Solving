class Solution {
public:
    bool checker(vector<int> &r, vector<int> &l, vector<int> &p)
    {
        for(int i=0;i<26;i++)
        {
//            cout<<r[i]<<" "<<l[i]<<" "<<p[i]<<endl;
            if((r[i]-l[i])!=p[i])
            return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n_s=s.length(), n_p=p.length();
        if(n_s<n_p) return {};
        vector<int> ans;
        vector<vector<int>> v(n_s+1,vector<int>(26,0));
        vector<int> pv(26,0);
        vector<int> pfx_sum(n_s+1);
        int p_sum=0;
        pfx_sum[0]=0;
        

        for(int i=0;i<n_p;i++)
        {
            p_sum+=(p[i]-'a');
            pv[(p[i]-'a')]++;
        }
        for(int i=0;i<n_s;i++)
        {
            v[i+1]=v[i];
            v[i+1][(s[i]-'a')]++;
            pfx_sum[i+1]=pfx_sum[i]+(s[i]-'a');
        }
        for(int i=0;i<n_s-n_p+1;i++)
        {
            if(pfx_sum[i+n_p]-pfx_sum[i]==p_sum && checker(v[i+n_p],v[i],pv))
            ans.push_back(i);
        }
        return ans;
    }
};
