class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        
        int ans = 0;
        int UnionBit = 0;
        int removeIdx = 0;

        for(int i=0; i < nums.size(); i++)
        {
            int newElement = nums[i];

            while(removeIdx <= i && (UnionBit & newElement) != 0)
            {
                int removeEl = nums[removeIdx];

                // remove the contribution of OR of this removeEl by performing XOR opeartion

                UnionBit = UnionBit ^ removeEl;
                removeIdx++;  
            }

            //now we are good to attach the element in Unionbit

            UnionBit |= newElement;

            ans = max(ans, i - removeIdx + 1);
        }

        return ans;
    }
};