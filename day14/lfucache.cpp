class LFUCache {
 public:
  LFUCache(int capacity) : capacity(capacity) {}

  int get(int key) { return addFrequency(false, key, 0); }

  void put(int key, int value) {
    if (capacity == 0) return;
    if (addFrequency(true, key, value) >= 0) return;
    if (h.size() >= capacity) {
      int popped_key = lfu_cache.begin()->second.back().first;
      lfu_cache.begin()->second.pop_back();
      if (lfu_cache.begin()->second.empty()) lfu_cache.pop_front();
      h.erase(popped_key);
    }
    if (lfu_cache.begin() != lfu_cache.end() && lfu_cache.begin()->first == 1) {
      lfu_cache.begin()->second.push_front({key, value});
      h[key] = {lfu_cache.begin(), lfu_cache.begin()->second.begin()};
    } else {
      lfu_cache.push_front({1, {{key, value}}});
      h[key] = {lfu_cache.begin(), lfu_cache.begin()->second.begin()};
    }
  }

 private:
  int addFrequency(bool update, int key, int value) {
    auto it = h.find(key);
    if (it == h.end()) return -1;
    if (!update) value = it->second.second->second;
    it->second.first->second.erase(it->second.second);
    auto next_it = next(it->second.first);
    if (next_it != lfu_cache.end() && next_it->first == it->second.first->first + 1) {
      next_it->second.push_front({key, value});
    } else {
      next_it = lfu_cache.insert(next_it, {it->second.first->first + 1, {{key, value}}});
    }
    if (it->second.first->second.empty()) {
      lfu_cache.erase(it->second.first);
    }
    h[key] = {next_it, next_it->second.begin()};
    return value;
  }

 private:
  using LRUType = list<pair<int, int>>;
  using LFUType = list<pair<int, LRUType>>;
  int capacity;
  LFUType lfu_cache;
  unordered_map<int, pair<LFUType::iterator, LRUType::iterator>> h;
};