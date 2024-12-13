class Solution {
public:
    bool isNotValid(vector<vector<int>>& consideredpoints, vector<vector<int>>& points)
    {
        vector<int> bl,br,tl,tr;
        bl = consideredpoints[0], tl = consideredpoints[1], br =consideredpoints[2], tr = consideredpoints[3];

        for(auto &it : points)
        {
            if(it == bl || it == br || it == tl || it == tr) continue;
            if(it[0] >= bl[0] && it[0] <= br[0] && it[1] >= bl[1] && it[1] <= tl[1]) return true;
        }
        return false;
    }

    int findArea(vector<vector<int>>& consideredpoints)
    {
        vector<int> bl,br,tl,tr;
        bl = consideredpoints[0], tl = consideredpoints[1], br =consideredpoints[2], tr = consideredpoints[3];

        if(bl[0] != tl[0] || br[0] != tr[0]) return -1;
        if(bl[1] != br[1] || tl[1] != tr[1]) return -1;

        return abs(br[0]-bl[0])*abs(tl[1] - bl[1]);
    }
    int maxRectangleArea(vector<vector<int>>& points) {
        int n= points.size(), ans = -1;
        sort(points.begin(), points.end());
        for(int i =0; i<n; i++)
        {
            cout<<points[i][0]<<" "<<points[i][1]<<endl;
        }
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                    for(int l=k+1; l<n; l++)
                    {
                        vector<vector<int>> consideredpoints = {points[i],points[j],points[k],points[l]};
                        sort(consideredpoints.begin(), consideredpoints.end());
                        int area = findArea(consideredpoints);
                        if(area == -1) continue;
                        if(isNotValid(consideredpoints, points))
                        {
                            continue;
                        }
                        
                        ans = max(ans, area);
                    }
                }
            }
        }
        return ans;
    }
};