class Solution {
public:
    int countPairs(vector<int> &arr, int target) {
        // Sort the array to use two-pointer approach
        sort(arr.begin(), arr.end());
        int count = 0;
        int start = 0, end = arr.size() - 1;
        
        while (start < end) {
            int sum = arr[start] + arr[end];
            
            if (sum >= target) {
                end--; // Decrease the sum by moving the right pointer
            } else {
                count += (end - start); // All pairs from start to end-1 are valid
                start++; // Increase the sum by moving the left pointer
            }
        }
        
        return count;
    }
};
