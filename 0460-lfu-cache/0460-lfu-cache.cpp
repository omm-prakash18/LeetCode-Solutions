#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

class LFUCache {
public:
    int cap;
    int minFreq;

    // key -> iterator in the corresponding frequency list
    unordered_map<int, list<vector<int>>::iterator> mp;
    // frequency -> list of {key, value, freq} (most recent at front)
    unordered_map<int, list<vector<int>>> freq;

    void updateFreq(int key) {
        auto it = mp[key];
        int val = (*it)[1];
        int f = (*it)[2];

        // Remove from current frequency list
        freq[f].erase(it);
        if (freq[f].empty()) {
            freq.erase(f);
            if (minFreq == f) {
                minFreq++;
            }
        }

        // Insert into new frequency list
        f++;
        freq[f].push_front({key, val, f});
        mp[key] = freq[f].begin();
    }

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        int value = (*(mp[key]))[1];
        updateFreq(key);
        return value;
    }
    
    void put(int key, int value) {
        if (cap == 0) return;

        // Key already exists: update value and increment frequency
        if (mp.find(key) != mp.end()) {
            (*(mp[key]))[1] = value;
            updateFreq(key);
            return;
        }

        // Evict LFU (and LRU tie-breaker) if cache is full
        if (mp.size() >= cap) {
            auto &lfuList = freq[minFreq];
            int evictKey = lfuList.back()[0];
            lfuList.pop_back();
            if (lfuList.empty()) {
                freq.erase(minFreq);
            }
            mp.erase(evictKey);
        }

        // Insert new entry with frequency 1
        minFreq = 1;
        freq[1].push_front({key, value, 1});
        mp[key] = freq[1].begin();
    }
};