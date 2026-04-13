class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       vector<int> freq(26, 0);
        for (char t : tasks) {
            freq[t - 'A']++;
        }

        priority_queue<int> maxHeap;
        for (int f : freq) {
            if (f > 0) maxHeap.push(f);
        }

        queue<pair<int, int>> q; // {remaining_count, available_time}
        int time = 0;

        while (!maxHeap.empty() || !q.empty()) {
            time++;

            if (!maxHeap.empty()) {
                int cnt = maxHeap.top();
                maxHeap.pop();
                cnt--;

                if (cnt > 0) {
                    q.push({cnt, time + n});
                }
            }

            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }

        return time; 
    }
};
