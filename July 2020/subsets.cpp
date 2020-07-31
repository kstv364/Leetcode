class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> curr;
        generate(0, nums, curr, subsets);
        return subsets;
    }

    void generate(int index, vector<int> &nums, vector<int> &curr, vector<vector<int>>& subsets) {
        vector<int> v1(curr);
        subsets.push_back(v1);
        for (int i = index; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            generate(i + 1, nums, curr, subsets);
            curr.pop_back();
        }
    }
};