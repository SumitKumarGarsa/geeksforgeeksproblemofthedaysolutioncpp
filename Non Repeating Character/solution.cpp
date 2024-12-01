class Solution {
public:
    char nonRepeatingChar(const string& s) {
        unordered_map<char, int> freq; // To store the frequency of each character

        // Step 1: Count the frequency of each character
        for (char ch : s) {
            freq[ch]++;
        }

        // Step 2: Traverse the string again to find the first non-repeating character
        for (char ch : s) {
            if (freq[ch] == 1) {
                return ch;
            }
        }

        // Step 3: If no non-repeating character is found, return '$'
        return '$';
    }
};
