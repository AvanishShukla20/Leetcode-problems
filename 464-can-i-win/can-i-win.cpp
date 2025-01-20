class Solution {
public:
    // Memoization array for storing game states
    int mem[1 << 20];

    bool canIWin(int M, int T) {
        int sum = M * (M + 1) / 2; // Sum of the entire choosable pool

        // If the target is less than 2, I can just pick 1 to win
        if (T < 2) return true;

        // If the sum of all numbers is less than the target, it's impossible to win
        if (sum < T) return false;

        // If the sum equals the target, the result depends on who plays last
        if (sum == T) return M % 2;

        // Non-trivial case: Perform DFS to evaluate the game
        memset(mem, 0, sizeof(mem)); // Clear the memoization array
        return dfs(M, T, 0);
    }

private:
    // Depth-first search to check if I can win
    bool dfs(int M, int T, int k) {
        // Check if this state has been computed
        if (mem[k] != 0) return mem[k] > 0;

        // If the target is already reached by the opponent, I lose
        if (T <= 0) return false;

        // Try all currently available numbers
        for (int i = 0; i < M; ++i) {
            // Check if the number (i+1) is available to pick
            if (!(k & (1 << i))) {
                // If the opponent can't win after I pick (i+1), I win
                if (!dfs(M, T - (i + 1), k | (1 << i))) {
                    mem[k] = 1; // Memorize this state as a win
                    return true;
                }
            }
        }

        // Otherwise, I lose
        mem[k] = -1; // Memorize this state as a loss
        return false;
    }
};
