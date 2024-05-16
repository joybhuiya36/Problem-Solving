#include<bits/stdc++.h>
using namespace std;

int main()
{
	int points[5][5],x,y;
	cin>>x,y;
	for(int i=0;i<5;i++)
	for(int j=0;j<2;j++)
	cin>>points[i][j];
	int m_dis=INT_MAX, dis,ind=-1;
        for(int i=0;i<5;i++)
        {
            if(points[i][0]==x||points[i][1]==y)
            {
                dis= abs(x-points[i][0])+abs(y-points[i][1]);
                if(m_dis>dis)
                {
                    m_dis=dis;
                    ind=i;
                }
            }
        }
        cout<<ind;
    return 0;
}

//class Solution {
//public:
//    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
//        int m_dis=INT_MAX, dis,ind=-1;
//        for(int i=0;i<points.size();i++)
//        {
//            if(points[i][0]==x||points[i][1]==y)
//            {
//                dis= abs(x-points[i][0])+abs(y-points[i][1]);
//                if(m_dis>dis)
//                {
//                    m_dis=dis;
//                    ind=i;
//                }
//            }
//        }
//        return ind;
//
//    }
//};
