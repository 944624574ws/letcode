#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i;
        vector<int> ans;
        ans.clear();
        map<int, int> dic;
        dic.clear();
        for(i=0;i<nums.size();i++)
           dic[nums[i]]=i+1;
        for(i=0;i<nums.size();i++)
        {
            int temp = target - nums[i];
            if(dic[temp]!=0&&(i+1)!=dic[temp])
            {
                ans.push_back(i+1);
                ans.push_back(dic[temp]);
                break;
            }
        }
        return ans;
    }
};

int main()
{
   vector<int> nums, x;
   while (scanf("%d", &x))
   {
       nums.push_back(x);
   }
   Solution so;
   //so = new Solution();
   vector<int> p = so.twoSum(&nums, 9);
   printf("index1=%d, index2=%d\n", p.at(0), p.at(1));
   system("pause");
   return 0;   
}
