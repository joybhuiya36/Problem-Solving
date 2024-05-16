class Solution {
public:
	bool isvowel(char c)
    {
        switch(c)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            return true;
            default:
            return false;
        }
        return false;
    }
    string sortVowels(string s) {
        string str="";
        int j=0;
        for(char &c:s)
        {
            if(isvowel(c))
            str+=c;
        }
        sort(str.begin(),str.end());
        for(int i=0;j<str.length();i++)
        {
            if(isvowel(s[i]))
            s[i]=str[j++];
        }
        return s;
    }
};
