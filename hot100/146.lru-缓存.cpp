/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
#include <map>
#include <list>

using namespace std;

template <typename Key, typename Value>
class LinkedHashMap
{
private:
    list<pair<Key, Value>> kv_list;
    map<Key, typename list<pair<Key, Value>>::iterator> data_map;

public:
    Value get(const Key &key)
    {
        if (data_map.find(key) == data_map.end())
        {
            return Value();
        }
        return data_map[key];
    }
    void put(const Key &key, const Value &value)
    {
        if (data_map.find(key) != data_map.end())
        {
            auto pos = data_map[key];
            kv_list.erase(pos);
            data_map.erase(key);
        }
        kv_list.push_back({key, value});
        data_map[key] = --kv_list.end();
    }
    Value
};

class LRUCache
{
private:
    int cap;
    LinkedHashMap<int, int> cache;

public:
    LRUCache(int capacity)
    {
        this->cap = capacity;
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end())
        {
            return -1;
        }
        makeRecently(key);
        return cache[key];
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            cache[key] = value;
            makeRecently(key);
            return;
        }
        if (cache.size() >= this->cap)
        {
            int old_key = cache.end()->first;
            cache.erase(old_key);
        }
        cache[key] = value;
    }

private:
    void makeRecently(int key)
    {
        int v = cache[key];
        cache.erase(key);
        cache[key] = v;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
