class Solution {
public:
    // Merge two sorted halves and count inversions
    int mergeAndCount(vector<int>& arr, int low, int mid, int high) {
        int n1 = mid - low + 1;
        int n2 = high - mid;

        // Create temporary arrays for left and right halves
        vector<int> left(arr.begin() + low, arr.begin() + mid + 1);
        vector<int> right(arr.begin() + mid + 1, arr.begin() + high + 1);

        int i = 0, j = 0, k = low, inversions = 0;

        // Merge the two halves while counting inversions
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
                inversions += (n1 - i); // Count all remaining elements in the left half
            }
        }

        // Copy any remaining elements from left
        while (i < n1) {
            arr[k++] = left[i++];
        }

        // Copy any remaining elements from right
        while (j < n2) {
            arr[k++] = right[j++];
        }

        return inversions;
    }

    // Recursive merge sort to count inversions
    int mergeSortAndCount(vector<int>& arr, int low, int high) {
        if (low >= high) return 0;

        int mid = low + (high - low) / 2;
        int inversions = 0;

        // Count inversions in the left half
        inversions += mergeSortAndCount(arr, low, mid);

        // Count inversions in the right half
        inversions += mergeSortAndCount(arr, mid + 1, high);

        // Count split inversions during merging
        inversions += mergeAndCount(arr, low, mid, high);

        return inversions;
    }

    // Main function to calculate inversion count
    int inversionCount(vector<int>& arr) {
        return mergeSortAndCount(arr, 0, arr.size() - 1);
    }
};
