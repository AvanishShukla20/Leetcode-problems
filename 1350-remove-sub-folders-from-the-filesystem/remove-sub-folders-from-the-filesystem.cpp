class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        ans.push_back(folder[0]);
        for(int i=1; i<folder.size(); i++)
        {
            string comp = ans.back();
            string curr = folder[i];
            int j = 0, k=0;
            while(j < comp.size())
            {
                if(curr[k] != comp[j])
                {
                    break;
                }
                k++;
                j++;
            }

            if(j < comp.size())
            {
                ans.push_back(curr);
            }
            else if(curr[k] != '/') ans.push_back(curr);
        }

        return ans;
    }
};