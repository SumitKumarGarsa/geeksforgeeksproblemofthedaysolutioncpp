class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Result vector to store merged intervals
        vector<vector<int>> ans;

        // Sort intervals based on their start times
        sort(arr.begin(), arr.end());

        // Initialize the result with the first interval
        ans.push_back(arr[0]);

        // Iterate through the intervals and merge overlapping ones
        for (int i = 1; i < arr.size(); i++) {
            if (ans.back()[1] >= arr[i][0]) {
                // Merge intervals by updating the end time
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            } else {
                // Add non-overlapping interval to the result
                ans.push_back(arr[i]);
            }
        }

        return ans;
    }
};
