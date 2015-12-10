#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() == 2)
           return 1;
           
        int res = 0;
        for (int i = 1, k = 0; i < nums.size(); i = i << 1, ++k)
        {
          int s1 = 0, s2 = 0;
          for (int j = 0; j < nums.size(); ++j)
          {
            s1 = s1 + ((nums[j] >> k) & 1);
            s2 = s2 + ((j >> k) & 1);
          }

          if (s1 > s2)
            res = pow(2.0, k*1.0) + res;
        }
        return res;
    }
};

int main()
{
    vector<int> nums;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
      cin >> x;
      nums.push_back(x);
    }
    Solution s;
    int res = s.findDuplicate(nums);
    cout << res;
    system("pause");
    return 0;
}
