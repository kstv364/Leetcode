class Solution {
    int abs(int a) {
        return a < 0 ? -a : a;
    }
public:
    vector<int> findDuplicates(vector<int>& a) {
        vector<int> ans;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (a[abs(a[i]) - 1] < 0)
                ans.push_back(abs(a[i])); // if already marked this is the 2nd occurence
            a[abs(a[i]) - 1] *= -1; // mark negative when visiting first time
        }
        return ans;

    }
};