#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int temp = 0;
        for (int i = 0; i < nums.size(); ++i)
           temp = temp ^ nums[i];
        return temp;
    }
};

int main()
{
    vector<int> nums;
    int x;
    while (cin >> x)
       nums.push_back(x);
    Solution so;
    int result = so.singleNumber(nums);
    cout << result << endl;
    system("pause");
    return 0;   
}
