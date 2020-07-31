class Solution {
public:
    int **visited;
    Solution() {
        visited = (int **)malloc(200 * sizeof(int *));
        for (int i = 0; i < 200; i++)
            visited[i] = (int *)malloc(200 * sizeof(int));
    }
    bool exist(vector<vector<char>>& arr, string word) {
        int m = arr.size();  int n = arr[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < arr[i].size(); j++) {
                visited[m][n] =  0;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < arr[i].size(); j++) {
                if (find(arr, i, j, word, 0)) {
                    return true;
                }

            }
        }
        return false;
    }

    bool find(vector<vector<char>> &arr , int m, int n, string &s, int i) {
        if (i == s.size())
            return true;
        if (m<0 or m>(arr.size() - 1) or n<0 or n>(arr[0].size() - 1))
            return false;
        else {
            if (visited[m][n] == 1)
                return false;
            if ((char)s[i] == arr[m][n]) {
                visited[m][n] = 1;
                bool ans =  find(arr, m - 1, n, s, i + 1) or find(arr, m, n - 1, s, i + 1) or find(arr, m + 1, n, s, i + 1) or find(arr, m, n + 1, s, i + 1);
                visited[m][n] = 0;
                return ans;
            }
            else {
                return false;
            }

        }

    }
};
