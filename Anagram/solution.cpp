class Solution{
public:
    // Function is to check whether two strings are anagram of each other or not.
bool areAnagrams(string s1, string s2) {
    // If the lengths of the strings are different, they can't be anagrams
    if (s1.size() != s2.size()) {
        return false;
    }

    // Create an array to store the frequency of characters
    vector<int> freq(26, 0);  // size 26 for 'a' to 'z'

    // Count frequency of characters in s1
    for (char c : s1) {
        freq[c - 'a']++;
    }

    // Subtract frequency based on s2
    for (char c : s2) {
        freq[c - 'a']--;
    }

    // Check if all values in the frequency array are zero
    for (int count : freq) {
        if (count != 0) {
            return false;
        }
    }

    return true;
}
};
