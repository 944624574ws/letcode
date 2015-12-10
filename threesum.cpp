#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        vector< vector<int> > result;
        result.clear();
        
        if (nums.size() < 3)
           return result;
                   
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); ++i)
        {
           if (i != 0 && nums[i] == nums[i - 1])
              continue;
           int l = i + 1, h = nums.size() - 1;
           while (l < h)
           {
              int temp = nums[i] + nums[l] + nums[h];
              int a = nums[l], b = nums[h];
              if (temp > 0)
                h--;
              else if (temp < 0)
                l++;
              else
              {
                 vector<int> t;
                 t.clear();
                 t.push_back(nums[i]);
                 t.push_back(nums[l]);
                 t.push_back(nums[h]);  
                 result.push_back(t);
                 
                 while (l < h && nums[l] == a) l++;
                 while (l < h && nums[h] == b) h--; 
              }
           }           
        }
        return result;
    }
};

int main()
{
   vector<int> nums;
   int x;
   while(cin >> x)
   {
      nums.push_back(x);          
   }
   Solution so;
   vector< vector<int> > result = so.threeSum(nums);
   for (int i = 0; i < result.size(); i++)
     cout << "(" << result[i].at(0)<<","<<result[i].at(1)<<","<<result[i].at(2)<<")"<<endl;
   system("pause");
   return 0;   
}
