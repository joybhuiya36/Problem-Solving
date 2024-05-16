class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
	    while(n!=0)
        {
            if(n%2==1)
            count++;
            n/=2;
        }
	return count;
    }
};
//Or
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int one_count = 0;
        while (n != 0) {
            one_count += (n%2);
            n >>= 1;
        }
        return one_count;
    }
};
//Or
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
	    string s= bitset<32>(n).to_string();
    	for(int i=0;s[i]!='\0';i++)
	        if(s[i]=='1')
            	count++;
	return count;
    }
};
