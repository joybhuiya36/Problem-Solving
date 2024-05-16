//(y1-y2)/(y2,y3)=(x1-x2)/(x2-x3)
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& co) {
        int dx=co[0][0]-co[1][0], dy=co[0][1]-co[1][1], n=co.size();
        for(int i=2;i<n;i++)
        {
            if(dx*(co[0][1]-co[i][1])!=dy*(co[0][0]-co[i][0]))
            return false;
        }
        return true;
    }
};
//y=mx+c
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& co) {
        double m,c;
        int flag=1;
        if((co[1][0]==co[0][0]))
		{
			for(int i=1;i<co.size()-1;i++)
			{
				if((co[i+1][0]!=co[i][0]))
				return 0;
			}
			return 1;
		}
		else if((co[1][1]==co[0][1]))
		{
				for(int i=1;i<co.size()-1;i++)
			{
				if((co[i+1][1]!=co[i][1]))
				return 0;
			}
			return 1;
		}
        else
        m=1.0*(co[1][1]-co[0][1])/(co[1][0]-co[0][0]);
        c=co[1][1]-(m*co[1][0]);
        for(int i=0;i<co.size();i++)
        {
            if(co[i][1]!=(m*co[i][0])+c)
            {
                flag=0;
                break;
            }
        }
        return flag;
    }
};
