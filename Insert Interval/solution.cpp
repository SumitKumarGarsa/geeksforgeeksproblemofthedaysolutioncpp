class Solution {
public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval) {
        // Resultant vector to store the merged intervals
        vector<vector<int>> ans;
        int n = intervals.size();
        int i = 0;

        // Add all intervals that come before the new interval
        while (i < n && newInterval[0] > intervals[i][1]) {
            ans.push_back(intervals[i]);
            i++;
        }

        // Merge overlapping intervals with the new interval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);

        // Add all intervals that come after the new interval
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};
