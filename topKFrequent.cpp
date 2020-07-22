

class CompareDist
{
public:
    bool operator()(pair<int, int> n1, pair<int, int> n2) {
        return n1.second < n2.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int> , vector<pair<int, int>>, CompareDist> pq;
        for (auto x : mp) {
            pq.push(x);
        }
        vector<int> ans;
        while (k--) {
            auto x = pq.top();
            pq.pop();
            ans.push_back(x.first);
        }
        return ans;

    }
};