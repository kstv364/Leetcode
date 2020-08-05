/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:

Input: 16
Output: true
Example 2:

Input: 5
Output: false
*/

class Solution {
public:
	bool isPowerOfFour(int n) {
		if (n == 1)    return true;
		queue<int> q;
		while (n > 0) {
			q.push(n % 4);
			n = n / 4;
		}
		if (q.front() != 0)    return false;
		while (q.front() == 0) q.pop();
		return q.size() == 1 and q.front() == 1;
	}
};