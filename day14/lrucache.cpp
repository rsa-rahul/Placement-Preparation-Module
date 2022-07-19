class LRUCache {
public:
	list<pair<int,int>> cache;
	unordered_map<int,list<pair<int,int>>::iterator> lru;
	int capacity;
	LRUCache(int capacity) {
		this->capacity = capacity; 
	}
	void reload(int key, int value)
	{
		cache.erase(lru[key]);
		cache.push_front({key,value});
		lru[key] = cache.begin();
	}
	int get(int key) {
		if(lru.find(key)!=lru.end())
		{
			reload(key,(*lru[key]).second);
			return (*lru[key]).second;
		}
		return -1;
	}

	void put(int key, int value) {
		if(lru.find(key)!=lru.end())
			reload(key,value);
		else
		{
			cache.push_front({key,value});
			lru[key] = cache.begin();
			if(lru.size() > capacity)
			{
				lru.erase(cache.back().first);
				cache.pop_back();
			}
		}
	}
};