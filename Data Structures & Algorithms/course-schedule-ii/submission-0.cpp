class Solution {
public:
    bool topo(int node,
              vector<vector<int>>& edges,
              stack<int>& st,
              vector<int>& vis,
              vector<int>& pathvis) {

        vis[node] = 1;
        pathvis[node] = 1;

        for (auto it : edges[node]) {

            if (!vis[it]) {
                if (topo(it, edges, st, vis, pathvis))
                    return true;
            }
            else if (pathvis[it]) {
                return true; // cycle found
            }
        }

        pathvis[node] = 0;
        st.push(node);

        return false; // no cycle
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> edges(numCourses);

        for (auto &it : prerequisites) {
            int u = it[0];
            int v = it[1];

            edges[v].push_back(u); // prerequisite -> course
        }

        stack<int> st;
        vector<int> vis(numCourses, 0);
        vector<int> pathvis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (topo(i, edges, st, vis, pathvis))
                    return {};
            }
        }

        vector<int> result;

        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};