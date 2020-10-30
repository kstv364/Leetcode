





class Solution {
public:

    string pad(string old_string) {
        return string(2 - old_string.length(), '0') + old_string;
    }

    int binary(string bin) {
        int ans = 0;
        for (int i = 0 ; i < bin.length(); i++) {
            ans = ans * 2 + (bin[i] == '1' ? 1 : 0);
        }
        return ans;
    }
    vector<string> readBinaryWatch(int num) {
        string permute (10 - num, '0');
        vector<string> ans;
        permute += string(num, '1');
        do {
            int h = binary(permute.substr(0, 4));
            int m = binary(permute.substr(4));
            if (h >= 0 and h <= 11 and m >= 0 and m <= 59) {
                ans.push_back(to_string(h) + ':' + pad(to_string(m)));
            }
        } while (next_permutation(permute.begin(), permute.end()));
        return ans;
    }
};