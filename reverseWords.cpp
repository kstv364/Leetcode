#include<bits/stdc++.h>

class Solution {
public:

    void split(vector<string> &flds, string work , char delim) {
        string buf = "";
        int i = 0;
        while (i < work.length()) {
            if ((char)work[i] != delim)
                buf += work[i];
            else if (buf.length() > 0) {
                flds.push_back(buf);
                buf = "";
            }
            i++;
        }
        if (!buf.empty())
            flds.push_back(buf);
    }

    string reverseWords(string s) {
        vector<string> ans;
        split(ans, s, ' ');
        if (ans.size() > 0) {
            string hmm = ans[0];
            for (int i = 1; i < ans.size(); i++) {

                hmm = ans[i]  + " " + hmm;
            }
            return hmm;
        }
        else
            return "";

    }


};