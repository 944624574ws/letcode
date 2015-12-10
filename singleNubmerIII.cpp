/**Single Number III**/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
           sum = sum ^ nums[i];
        
        int temp = 1;
        while ((sum & 1) == 0)
        {
            sum = sum >> 1;
            temp = temp << 1;
        }

        vector<int> res(2);
        res[0] = 0;
        res[1] = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if ((nums[i] & temp) == 0)
               res[0] = res[0] ^ nums[i];
            else
               res[1] = res[1] ^ nums[i];
        }
        return res;
    }
    
};

int main()
{
   vector<int> nums;
   int x;
   while (cin >> x)
      nums.push_back(x);
   Solution so;
   vector<int> result = so.singleNumber(nums);
   cout << result[0] << " " << result[1] << endl;
   system("pause");
   return 0;
}
