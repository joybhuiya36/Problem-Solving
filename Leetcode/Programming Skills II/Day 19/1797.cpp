class AuthenticationManager {
    unordered_map<string,int> mp;
    int time;
public:
    AuthenticationManager(int timeToLive) {
        time=timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId]=currentTime+time;
    }
    
    void renew(string tokenId, int currentTime) {
        //cout<<tokenId<<" outer "<<mp[tokenId]<<endl;
        if(mp[tokenId]>0 && mp[tokenId]>currentTime)
        {
            //cout<<tokenId<<" inner 1 "<<mp[tokenId]<<endl;
            mp[tokenId]=currentTime+time;
            //cout<<tokenId<<" inner 2 "<<mp[tokenId]<<endl;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count=0;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            //cout<<it->first<<" "<<it->second<<endl;
            if(it->second>currentTime)
            count++;
        }
        return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
