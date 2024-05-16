class Solution {
public:
bool vowel(char &ch)
{
    switch(ch)
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
    }
    return false;
}
    bool halvesAreAlike(string s) {
        int a=0,b=0,i=0,j=s.length()-1;
        while(i<j)
        {
            if(vowel(s[i]))
            a++;
            if(vowel(s[j]))
            b++;
            i++; j--;
        }
        return a==b;
    }
};
