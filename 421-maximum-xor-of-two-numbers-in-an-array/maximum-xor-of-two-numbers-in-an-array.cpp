class Solution {
public:
    struct trieNode{
        trieNode* left; // 0
        trieNode* right; // 1
    };

    void insertNum(trieNode* root, int num)
    {
        trieNode* temp = root;

        for(int i=31; i>=0; i--)
        {
            int ith_bit = ((num >> i) & 1);
            if(ith_bit == 0)
            {
                if(temp->left == NULL)
                {
                    temp->left = new trieNode();
                }
                temp = temp->left;
            }
            if(ith_bit == 1)
            {
                if(temp->right == NULL)
                {
                    temp->right = new trieNode();
                }
                temp = temp->right;
            }
        }
    }
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();

        trieNode* root = new trieNode();

        for(int i=0; i<n; i++)
        {
            insertNum(root, nums[i]);
        }

        int result = 0;

        for(int i=0; i<n; i++)
        {
            int val = nums[i];
            trieNode* t = root;
            int ans = 0;
            for(int j=31; j>=0; j--)
            {
                int bit = ((val>>j)&1);
                if(bit == 0)
                {
                    if(t->right != NULL) 
                    {
                        ans |= (1<<j);
                        t = t->right;
                    }
                    else t = t->left; 
                }
                else
                {
                    if(t->left != NULL) 
                    {
                        ans |= (1<<j) ;
                        t = t->left;
                    }
                    else t = t->right;
                }
            }

            result = max(result, ans);
        }

        return result;
    }
};