class Solution {
public:
    int countOverlaps(vector<vector<int>>& A, vector<vector<int>>& B, int rowshift, int colshift)
    {
        int m=A.size(), n=A[0].size(), cnt =0;

        for(int i=0; i<m; i++)
        {
            for(int j =0; j<n; j++)
            {
                int other_i = i + rowshift;
                int other_j = j + colshift;

                if(other_i>=0&&other_i<m&&other_j>=0&&other_j<n)
                {
                    if(A[i][j] == B[other_i][other_j] && A[i][j] == 1) cnt++;
                }
            }
        }

        return cnt;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int m=img1.size(), n=img2.size();

        int maxi = 0;

        for(int rowshift = -m+1; rowshift < m; rowshift++)
        {
            for(int colshift = -n+1; colshift < n; colshift++)
            {
                maxi = max(maxi, countOverlaps(img1, img2, rowshift, colshift));
            }
        }
        return maxi;
    }
};