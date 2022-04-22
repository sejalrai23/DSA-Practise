class MyHashMap {
    vector<list<pair<int,int>>> m_data;
    size_t m_size = 10000;
public:
    MyHashMap() {
        m_data.resize(m_size);
    }
    
    void put(int key, int value) {
        auto &list = m_data[key % m_size];
        for (auto & val : list) {
            if (val.first == key) {
                val.second = value;
                return;
            }
        }
        list.emplace_back(key, value);
    }
    
    int get(int key) {
        const auto &list = m_data[key % m_size];
        if (list.empty()) {
            return -1;
        }
        for (const auto & val : list) {
            if (val.first == key) {
                return val.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        auto& pairs = m_data[key%m_size];
        for(auto i=pairs.begin(); i!= pairs.end(); i++)
        {
            if(i->first==key) { pairs.erase(i); return; }
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