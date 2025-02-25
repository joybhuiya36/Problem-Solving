//Vector
class MyHashMap {
    vector<int> v;
public:
    MyHashMap() {
        v.resize(1000001,-1);
    }
    
    void put(int key, int value) {
        v[key]=value;
    }
    
    int get(int key) {
        return v[key];
    }
    
    void remove(int key) {
        v[key]=-1;
    }
};
//By key%size storing approach
class MyHashMap {
	vector<vector<pair<int, int>>> map;
	const int size = 10000;
public:
	MyHashMap() {
		map.resize(size);
	}

	void put(int key, int value) {
		int index = key % size;
        vector<pair<int, int>> &row = map[index];
        for(auto iter = row.begin(); iter != row.end(); iter++)
        {
            if(iter->first == key)
            {
                iter->second = value;
                return;
            }
        }
		row.push_back(make_pair(key, value));
	}
	int get(int key) {
		int index = key % size;
        vector<pair<int, int>> &row = map[index];
		for (auto iter = row.begin(); iter != row.end(); iter++)
		{
			if (iter->first == key)
			{
				return iter->second;
			}
		}
		return -1;
	}

	void remove(int key) {
		int index = key % size;
        vector<pair<int, int>> &row = map[index];
		for (auto iter = row.begin(); iter != row.end(); iter++)
		{
			if (iter->first == key)
			{
				row.erase(iter);
                return;
			}
		}
	}
};
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
