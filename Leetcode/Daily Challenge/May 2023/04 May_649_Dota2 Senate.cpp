//"RD"
//"RDD"
//"RRDDD"
//"RRRDDDDD"
//"RRRDDDDDD"
//"RRRDDDD"
//"DRRDRDRDRDDRDRDR"
//"DRRDRD"
class Solution {
public:
    string predictPartyVictory(string senate) {
        int r=0,d=0, r_live, d_live;
        string s;
        while(1)
        {
            r_live=0; d_live=0; s="";
            for(int i=0;i<senate.length();i++)
            {
                if(senate[i]=='R')
                {
                    if(d>0)
                    {
                        d--;
                        continue;
                    }
                    else
                    {
                        r_live++;
                        r++;
                        s+=senate[i];
                    }
                }
                else if(senate[i]=='D')
                {
                    if(r>0)
                    {
                        r--;
                        continue;
                    }
                    else
                    {
                        d_live++;
                        d++;
                        s+=senate[i];
                    }
                }
            }
            if(d_live==0)
            return "Radiant";
            if(r_live==0)
            return "Dire";
            senate=s;
        }
        
    }
};
