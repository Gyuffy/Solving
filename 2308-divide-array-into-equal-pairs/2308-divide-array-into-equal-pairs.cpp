#include <cstring>
int dat[1001] = {0, };

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            dat[nums[i]]++;
        }

        for (int i = 1; i <= 1000; i++)
        {
            if(dat[i] % 2 == 1)
            {
                memset(dat, 0, sizeof(dat));
                return false;
            }
            else if(i == 1000)
            {
                memset(dat, 0, sizeof(dat));
                return true;
            }
        }

        return false;
};
};