class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        double res = 0.0;
        priority_queue<pair<double, int>> pq;

        for(int i=0; i<n; i++)
        {
            double pr = (double)classes[i][0]/classes[i][1];
            double npr = (double)(classes[i][0]+1)/(classes[i][1]+1);

            double diff = npr - pr;
            pq.push({diff, i});
        }
        
        

        while(extraStudents--)
        {
            auto x = pq.top();
            pq.pop();
            double diff = x.first;
            int idx = x.second;

            classes[idx][0]++;
            classes[idx][1]++;

            //now for next iteration this idx will give new PR as it is changed here.For Rest of There will be no change !!

            double curr_pr = (double)classes[idx][0]/classes[idx][1];
            double new_curr_pr = (double)(classes[idx][0]+1)/(classes[idx][1]+1);

            double ndiff = new_curr_pr - curr_pr;
            pq.push({ndiff, idx});

        }

        for(int i=0; i<n; i++)
        {
            res += (double)classes[i][0]/classes[i][1];
        }

        return 1.0*res/n;

    }
};