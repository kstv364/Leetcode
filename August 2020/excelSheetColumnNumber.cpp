class Solution {
public:
	int titleToNumber(string s) {
		int ans = 0, n;
		for (int i = 0; i < s.length(); i++) {
			n = s[i] - 64;
			ans = ans * 26 + n;
		}
		return ans;
	}
};