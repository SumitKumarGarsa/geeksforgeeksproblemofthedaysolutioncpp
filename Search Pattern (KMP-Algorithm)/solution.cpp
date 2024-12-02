class Solution {
public:
    void computeLPSArray(const string& pat, vector<int>& lps) {
        int len = 0, i = 1;
        int M = pat.size();
        
        lps[0] = 0;  // lps[0] is always 0
        
        while (i < M) {
            if (pat[i] == pat[len]) {
                lps[i++] = ++len;
            } else if (len) {
                len = lps[len - 1];  // fall back to previous valid prefix length
            } else {
                lps[i++] = 0;
            }
        }
    }

    vector<int> search(const string& pat, const string& txt) {
        vector<int> res, lps(pat.size(), 0);
        int M = pat.size(), N = txt.size();
        int i = 0, j = 0;

        computeLPSArray(pat, lps);
        
        while (i < N) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }

            if (j == M) {
                res.push_back(i - j);  // Found a match
                j = lps[j - 1];  // Use the LPS array to skip redundant checks
            } else if (i < N && pat[j] != txt[i]) {
                if (j) {
                    j = lps[j - 1];  // Use LPS array to skip some comparisons
                } else {
                    i++;  // Move to next character in txt
                }
            }
        }
        
        return res;
    }
};
