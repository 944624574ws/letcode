#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

struct TwoSum{
    int x, y;
    int val;
};

class Solution {
public:
    static bool compare(const struct TwoSum& a, const struct TwoSum& b)
    {
        return a.val < b.val;
    }
    
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        for (int i = 0; i < 4; ++i)
           if (a[i] - b[i] > 0)
              return true;
           else if (a[i] - b[i] < 0)
              return false;
           else
              continue;
        return true;      
    }
           
    bool legal(const struct TwoSum& a, const struct TwoSum& b)
    {
        if (min(a.x, a.y) > max(b.x, b.y) || min(b.x, b.y) > max(a.x, a.y)) 
           return true;
        else
           return false;
    }
    
    bool equal(vector<int>& a, vector<int>& b)
    {
       for (int i = 0; i < 4; ++i)
          if (a[i] != b[i])
             return false;
        return true;     
    }
         
    vector< vector<int> > fourSum(vector<int>& nums, int target) {
        vector< vector<int> > res;
        res.clear();
        if (nums.size() < 4)
           return res;
        
        if (nums.size() == 4)
        {
            sort(nums.begin(), nums.end());
            for (int i = 0; i < 4; ++i)
               target -= nums[i];
            if (target == 0)
                res.push_back(nums);
            return res;
        }
        
        vector<TwoSum> tmp;  
        tmp.clear();
        for (int i = 0; i < nums.size() - 1; ++i)
          for (int j = i + 1; j < nums.size(); ++j)
          {
              struct TwoSum ts;
              ts.x = i;
              ts.y = j;
              ts.val = nums[i] + nums[j];
              tmp.push_back(ts);
          }
  
        printf("before\n");
        for (int i = 0; i < tmp.size(); ++i)
           cout<<tmp[i].x<<"-"<<tmp[i].y<<"-"<<tmp[i].val<<endl;
        sort(tmp.begin(), tmp.end(), compare);
        printf("after\n");
        for (int i = 0; i < tmp.size(); ++i)
           cout<<tmp[i].x<<"-"<<tmp[i].y<<"-"<<tmp[i].val<<endl;
        
        int l = 0, h = tmp.size() - 1;
        
        while (l < h)
        {
            if (tmp[l].val + tmp[h].val > target)
               --h;
            else if (tmp[l].val + tmp[h].val < target)
               ++l;
            else
            {
                int k = h;                
                while (tmp[l].val + tmp[k].val == target)
                {
                    if (legal(tmp[l], tmp[k]))
                    {
                        vector<int> v;
                        v.clear();
                        v.push_back(nums[tmp[l].x]);
                        v.push_back(nums[tmp[l].y]);
                        v.push_back(nums[tmp[k].x]);
                        v.push_back(nums[tmp[k].y]);
                        sort(v.begin(), v.end());
                        res.push_back(v); 
                    } 
                    --k;
                }
                
                ++l;
            }
        } 
        sort(res.begin(), res.end(), cmp);  
        vector< vector<int> > result;
        result.clear();
        for (int i = 0; i < res.size(); ++i)
           if (i != 0 && equal(res[i], res[i - 1]))
              continue;
           else
              result.push_back(res[i]);
    
        return result;
    }
};

int main()
{
    vector<int> v;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin>>x;
       v.push_back(x);    
    }
    Solution so;
    int target;
    cin>>target;
    vector< vector<int> > res = so.fourSum(v, target);
    for (int i = 0; i < res.size(); ++i)
    {
       vector<int> v = res[i];
       for (int j = 0; j < 4; ++j)
          cout << v[j] << " ";
       cout<<endl;    
    }
    system("pause");
    return 0;   
}
