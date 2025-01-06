class Solution {
public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // Sort the array for two-pointer approach
        sort(arr.begin(), arr.end());
        
        int start = 0, end = arr.size() - 1;
        int closestDiff = INT_MAX;
        vector<int> result;
        
        while (start < end) {
            int pairSum = arr[start] + arr[end];
            int currentDiff = abs(target - pairSum);
            
            // Update the result if the current pair is closer to the target
            if (currentDiff < closestDiff) {
                closestDiff = currentDiff;
                result = {arr[start], arr[end]};
            }
            
            // Move the pointers based on the pair sum
            if (pairSum < target) {
                start++;
            } else if (pairSum > target) {
                end--;
            } else {
                return result; // Exact match found
            }
        }
        
        return result;
    }
};
