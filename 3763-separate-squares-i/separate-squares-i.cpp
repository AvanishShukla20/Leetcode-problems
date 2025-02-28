class Solution {
public:

    double getMinY(vector<vector<int>>& squares)
    {
        double mini = 1e12;
        for(auto &it : squares)
        {
            // this is most imp step everyone misses-> multiply by 1.0
            mini = min(mini, it[1]*1.0); 
        }
        return mini;
    }
    double getMaxY(vector<vector<int>>& squares)
    {
        double maxi = -1;
        for(auto &it : squares)
        {
            maxi = max(maxi, (it[1]+it[2])*1.0); 
        }
        return maxi;
    }


    bool isAreaBelowGreater(double mid, vector<vector<int>>& squares)
    {
        double belowArea = 0.00, aboveArea = 0.00;

        for(auto &sq : squares)
        {
            double bottom = sq[1]*1.0, side = sq[2]*1.0, top = (sq[1] + sq[2])*1.0;

            if(mid >= top)
            {
                belowArea += side*side;
            }
            else if(mid <= bottom)
            {
                aboveArea += side*side;
            }
            else
            {
                belowArea += (mid - bottom)*side;
                aboveArea += (top - mid)*side;
            }
        }

        return belowArea >= aboveArea ;

    }

    double separateSquares(vector<vector<int>>& squares) {
        int n=squares.size();

        double low = getMinY(squares);
        double high = getMaxY(squares);
        double mid, ans, precision = 1e-5; // 10^-5 is represented as 1e-5

        while(high-low >= precision)
        {
            mid = low + (high-low)/2;

            if(isAreaBelowGreater(mid, squares) == true)
            {
                ans = mid;
                high = mid;
            }
            else low = mid;
        }
        return ans;
    }
};