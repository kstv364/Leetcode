/*.Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:
Input: [[1,2], [3], [3], []]
Output: [[0,1,3],[0,2,3]]
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Note:

The number of nodes in the graph will be in the range [2, 15].
You can print different paths in any order, but you should keep the order of nodes inside one path.
*/

class Solution {
public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		vector<vector<int>> ans;
		int n = graph.size();
		int src = 0 , des = n - 1;
		int visited[n];
		memset(visited, 0, sizeof(visited));
		vector<int> tmp;
		DFSUtil(visited, 0, n, tmp, ans, graph);
		return ans;
	}

	void DFSUtil(int visited[], int u, int n,
	             vector<int> &tmp,
	             vector<vector<int>> &ans,
	             vector<vector<int>>& graph) {

		visited[u] = 1;
		tmp.push_back(u);
		if (u == n - 1) {
			ans.push_back(vector<int> (tmp));
		}
		else {
			for (auto it = graph[u].begin(); it != graph[u].end(); it++) {
				if (!visited[*it]) {
					DFSUtil(visited, *it, n, tmp, ans, graph);
				}
			}
		}
		visited[u] = 0;
		tmp.pop_back();
	}
};