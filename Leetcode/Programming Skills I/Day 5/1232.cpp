#include<bits/stdc++.h>
using namespace std;

int main()
{
	    int co[3][2];
		double m,c,flag=1;
		for(int i=0;i<3;i++)
		for(int j=0;j<2;j++)
		cin>>co[i][j];
		
		if((co[1][0]==co[0][0]))
		{
			for(int i=1;i<4-1;i++)
			{
				if((co[i+1][0]!=co[i][0]))
				return 0;
			}
			return 1;
		}
		else if((co[1][1]==co[0][1]))
		{
				for(int i=1;i<4-1;i++)
			{
				if((co[i+1][1]!=co[i][1]))
				return 0;
			}
			return 1;
		}
        m=1.0*(co[1][1]-co[0][1])/(co[1][0]-co[0][0]);
        c=co[1][1]-(m*co[1][0]);
        cout<<m<<" "<<c<<endl;
        for(int i=0;i<3;i++)
        {
            if(co[i][1]!=(m*co[i][0])+c)
            {
                flag=0;
                break;
            }
        }
        cout<<flag;
        //return flag;
}



//class Solution {
//public:
//    bool checkStraightLine(vector<vector<int>>& co) {
//        double m,c;
//        int flag=1;
//        if((co[1][0]==co[0][0]))
//		{
//			for(int i=1;i<co.size()-1;i++)
//			{
//				if((co[i+1][0]!=co[i][0]))
//				return 0;
//			}
//			return 1;
//		}
//		else if((co[1][1]==co[0][1]))
//		{
//				for(int i=1;i<co.size()-1;i++)
//			{
//				if((co[i+1][1]!=co[i][1]))
//				return 0;
//			}
//			return 1;
//		}
//        else
//        m=1.0*(co[1][1]-co[0][1])/(co[1][0]-co[0][0]);
//        c=co[1][1]-(m*co[1][0]);
//        for(int i=0;i<co.size();i++)
//        {
//            if(co[i][1]!=(m*co[i][0])+c)
//            {
//                flag=0;
//                break;
//            }
//        }
//        return flag;
//    }
//};




//class Solution {
//public:
//    bool checkStraightLine(vector<vector<int>>& coordinates) {
//        
//    }
//};
