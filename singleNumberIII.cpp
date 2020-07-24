
/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int a = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            a = a ^ nums[i];
        }
        int set_bit_no = a & ~(a - 1);
        int x = 0, y = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]&set_bit_no)
                x = x ^ nums[i];
            else
                y = y ^ nums[i];
        }
        vector<int> v;
        v.push_back(x);
        v.push_back(y);
        return v;
    }
};