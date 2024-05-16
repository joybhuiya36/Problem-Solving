class Solution {
public:
    string freqAlphabets(string s) {
        string str;
        int n=s.length();
        int i=0;
        while(i<n)
        {
            if(s[i]=='1'&& s[i+2]=='#')
            {
                str+=char(106+int(s[i+1]-'0'));
                i+=3;
            }
            else if(s[i]=='2'&& s[i+2]=='#')
            {
                str+=char(116+int(s[i+1]-'0'));
                i+=3;
            }
            else
            {
                str+=char(97+int(s[i]-'1'));
                i++;
            }
        }
        return str;
    }
};
