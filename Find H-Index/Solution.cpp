class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> freq(n + 1, 0); // Frequency array to count citations
        
        // Count the number of papers for each citation value
        for (int i = 0; i < n; i++) {
            if (citations[i] >= n) {
                freq[n]++; // Papers with citations >= n are grouped together
            } else {
                freq[citations[i]]++;
            }
        }
        
        // Calculate the H-index
        int Hindex = n; // Start from the maximum possible H-index
        int numPapers = freq[n]; // Papers with citations >= Hindex
        while (numPapers < Hindex) {
            Hindex--;
            numPapers += freq[Hindex]; // Accumulate papers with citations >= Hindex
        }
        
        return Hindex;
    }
};
