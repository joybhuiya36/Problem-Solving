//Bit Manipulation
//Left MSB single bit removing
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        uint32_t first_digit;
        int digit;
        int i=0;
        while(n)
        {
            first_digit=n&(1<<31);
            if(first_digit==0)
            digit=0;
            else digit=1;
            // cout<<digit<<endl;
            n=n<<1;
            ans|=digit<<i++;
            // cout<<bitset<32>(ans).to_string()<<endl;
        }
        return ans;
    }
};
//Right LSB signle bit removing
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        for(int i=0;i<32;i++){
            //get last bit of n
            int bit=n&1;
            n=n>>1;
            res=res<<1;
            res+=bit;
        }
        return res;
    }
};
//By string and bitset<32>
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string s=bitset<32>(n).to_string();
        reverse(s.begin(),s.end());
        uint32_t ans=bitset<32>(s).to_ulong();
        return ans;
    }
};
