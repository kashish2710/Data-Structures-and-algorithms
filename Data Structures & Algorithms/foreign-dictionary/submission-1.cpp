class Solution {
public:

    void toposort(vector<int>& topo,
                  vector<vector<int>>& adj,
                  vector<int>& present) {

        vector<int> indegree(26, 0);

        for(auto it : adj) {
            for(int num : it) {
                indegree[num]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < 26; i++) {
            if(present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(auto it : adj[node]) {
                indegree[it]--;

                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
    }

    string foreignDictionary(vector<string>& words) {

        int n = words.size();

        vector<vector<int>> adj(26);
        vector<int> present(26, 0);

        // Mark present characters
        for(auto &word : words) {
            for(char ch : word) {
                present[ch - 'a'] = 1;
            }
        }

        // Build graph
        for(int i = 0; i < n - 1; i++) {

            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.size(), s2.size());

            // Invalid prefix case: ["abc", "ab"]
            if(s1.size() > s2.size() &&
               s1.substr(0, len) == s2) {
                return "";
            }

            for(int ptr = 0; ptr < len; ptr++) {

                if(s1[ptr] != s2[ptr]) {

                    adj[s1[ptr] - 'a']
                        .push_back(s2[ptr] - 'a');

                    break;
                }
            }
        }

        vector<int> topo;

        toposort(topo, adj, present);


        int total = 0;

        for(int i = 0; i < 26; i++) {
            if(present[i]) {
                total++;
            }
        }

        if(topo.size() != total) {
            return "";
        }

        string ans = "";

        for(int num : topo) {
            ans += char(num + 'a');
        }

        return ans;
    }
};