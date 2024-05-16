//Optimal Solution
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), n = B.size();
        int i = 0, j = 0;
        vector<vector<int>> res;

        while(i < m && j < n) {
            int lo = max(A[i][0], B[j][0]);
            int hi = min(A[i][1], B[j][1]);

            if(lo <= hi) {
                res.push_back({lo, hi});
            }

            if(A[i][1] < B[j][1]) {
                ++i;
            } else {
                ++j;
            }
        }

        return res;
    }
};
//My Solution
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& fl, vector<vector<int>>& sl) {
        int m=fl.size(), n=sl.size();
        if(m==0 || n==0)
        return {};
        vector<vector<int>> v;
        int i=0,j=0;
        while(i<m && j<n)
        {
            if(fl[i][1]<sl[j][1])
            {
                if(fl[i][1]<sl[j][0])
                {
                    i++;
                    continue;
                }
                if(fl[i][0]<sl[j][0])
                v.push_back({sl[j][0],fl[i][1]});
                else v.emplace_back(fl[i]);
                i++;
            }
            else if(fl[i][1]>sl[j][1])
            {
                if(fl[i][0]>sl[j][1])
                {
                    j++;
                    continue;
                }
                if(fl[i][0]>sl[j][0])
                v.push_back({fl[i][0],sl[j][1]});
                else v.emplace_back(sl[j]);
                j++;
            }
            else
            {
                if(fl[i][0]>=sl[j][0])
                v.emplace_back(fl[i]);
                else v.emplace_back(sl[j]);
                i++; j++;
            }
        }
        return v;
    }
};
