class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        vector<vector<int>> shared(n, vector<int>(n, 0));
        
        // Compute overlap between each pair of strings
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    for (int k = min(A[i].size(), A[j].size()); k >= 0; k--) {
                        if (A[i].substr(A[i].size() - k) == A[j].substr(0, k)) {
                            shared[i][j] = k;
                            break;
                        }
                    }
                }
            }
        }
        
        int total_states = 1 << n; // 2^n possible sets
        vector<vector<string>> dp(total_states, vector<string>(n, ""));
        
        // Initialize DP table
        for (int i = 0; i < total_states; i++) {
            for (int k = 0; k < n; k++) {
                if (!(i & (1 << k))) continue; // If k-th bit is not set in i, skip
                if (i == (1 << k)) {
                    dp[i][k] = A[k];
                    continue;
                }
                
                for (int j = 0; j < n; j++) {
                    if (j == k || !(i & (1 << j))) continue; // Skip if j is not part of the set
                    
                    string candidate = dp[i ^ (1 << k)][j] + A[k].substr(shared[j][k]);
                    if (dp[i][k].empty() || candidate.size() < dp[i][k].size()) {
                        dp[i][k] = candidate;
                    }
                }
            }
        }
        
        // Find the shortest superstring among all possibilities
        string result;
        int min_len = numeric_limits<int>::max();
        for (int i = 0; i < n; i++) {
            string s = dp[total_states - 1][i];
            if (s.size() < min_len) {
                min_len = s.size();
                result = s;
            }
        }
        
        return result;
    }
};