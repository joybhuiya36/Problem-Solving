class UndergroundSystem {
public:
unordered_map<int,pair<string,int>> psn;
unordered_map<string,pair<int,int>> station;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        psn[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string,int> p=psn[id];
        psn.erase(id);
        pair<int,int> data=station[p.first+"-"+stationName];
        station[p.first+"-"+stationName]={data.first+(t-p.second),data.second+1};
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<int,int> p=station[startStation+"-"+endStation];
        return (1.0*p.first)/p.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
