class Solution {
public:
    int minRemoval(vector<vector<int>>& intervals) {
        // Handle edge case: If no intervals, nothing to remove
        if (intervals.empty()) return 0;

        // Sort intervals based on their start time (ascending order)
        sort(intervals.begin(), intervals.end());

        int removalCount = 0; // Count of intervals to remove
        int previousEnd = intervals[0][1]; // End time of the last non-overlapping interval

        // Iterate through the intervals starting from the second one
        for (int i = 1; i < intervals.size(); ++i) {
            // Check for overlap
            if (intervals[i][0] < previousEnd) {
                // Overlapping: Remove the interval with the larger end time
                ++removalCount;
                previousEnd = min(previousEnd, intervals[i][1]);
            } else {
                // No overlap: Update the end time
                previousEnd = intervals[i][1];
            }
        }

        return removalCount;
    }
};
