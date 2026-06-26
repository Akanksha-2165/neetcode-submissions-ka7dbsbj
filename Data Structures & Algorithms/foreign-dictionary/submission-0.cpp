class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        // Graph: stores character -> characters that must come after it
        unordered_map<char, unordered_set<char>> graph;

        // indegree[ch] = number of characters that must come before ch
        unordered_map<char, int> indegree;

        // Add every unique character to graph and indegree
        for (auto &word : words) {
            for (char ch : word) {
                graph[ch];
                indegree[ch] = 0;
            }
        }

        // Build graph by comparing adjacent words
        for (int i = 0; i < words.size() - 1; i++) {

            string w1 = words[i];
            string w2 = words[i + 1];

            // Invalid case:
            // "abc" comes before "ab"
            if (w1.size() > w2.size() &&
                w1.substr(0, w2.size()) == w2)
                return "";

            int len = min(w1.size(), w2.size());

            // Find first different character
            for (int j = 0; j < len; j++) {

                if (w1[j] != w2[j]) {

                    // Add edge only if it doesn't already exist
                    if (!graph[w1[j]].count(w2[j])) {
                        graph[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }

                    // Only first difference matters
                    break;
                }
            }
        }

        // Queue for all characters having indegree 0
        queue<char> q;

        for (auto &p : indegree) {
            if (p.second == 0)
                q.push(p.first);
        }

        string ans;

        // Standard Kahn's Topological Sort
        while (!q.empty()) {

            char curr = q.front();
            q.pop();

            ans += curr;

            // Remove outgoing edges
            for (char nei : graph[curr]) {

                indegree[nei]--;

                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }

        // Cycle exists
        if (ans.size() != indegree.size())
            return "";

        return ans;
    }
};
