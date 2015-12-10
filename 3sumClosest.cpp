#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
           
        int min = INT_MAX, res = 0;  
        for (int i = 0; i < nums.size() - 2; ++i)
           for (int j = i + 1; j < nums.size(); ++j)
           {
               int l = j + 1, h = nums.size() - 1;
               while (l <= h)
               {
                   int mid = (l + h) / 2;
                   int s = nums[i] + nums[j] + nums[mid];
                   if (abs(s - target) < min)
                   {
                       min = abs(s - target);
                       res = s;
                   }
                   if (s < target)
                      l = mid + 1;
                   else if (s > target)
                      h = mid - 1;
                   else
                     return target;
               }
           }
        return res;
    }
};

int main()
{
   
   int n, x;
   cin >> n;
   vector<int> v;
   for (int i = 0; i < n; ++i)
   {
       cin >> x;
       v.push_back(x);
   }

   Solution so;
   int target;
   cin>>target;
   cout<<so.threeSumClosest(v, target)<<endl;
   system("pause");
   return 0;   
}
