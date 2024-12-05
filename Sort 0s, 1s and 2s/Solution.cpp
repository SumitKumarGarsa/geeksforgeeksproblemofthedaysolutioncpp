class Solution {
public:
    void sort012(vector<int>& arr) {
        // Initialize counters for 0s and 1s
        int zeros = 0, ones = 0;
        
        // Count the occurrences of 0s and 1s in the array
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) {
                zeros++;
            } else if (arr[i] == 1) {
                ones++;
            }
        }

        // Refill the array with 0s, 1s, and 2s based on the counts
        for (int i = 0; i < arr.size(); i++) {
            if (zeros > 0) {
                arr[i] = 0;
                zeros--;
            } else if (ones > 0) {
                arr[i] = 1;
                ones--;
            } else {
                arr[i] = 2;
            }
        }
    }
};
