#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:            
    double findMedianById(vector<int>& nums1, int l1, int h1, vector<int>& nums2, int l2, int h2, int id)
    {
        if (l1 > h1)
           return nums2[l2 + id - 1];
        if (l2 > h2)
           return nums1[l1 + id - 1];
           
        if (h2 - l2 + 1 + h1 - l1 + 1 == id)
           return nums1[h1] > nums2[h2] ? nums1[h1] : nums2[h2];
           
        if (h1 - l1 == 0)
        { 
            if (nums2[l2 +id - 1] <= nums1[l1])
               return nums2[l2 + id - 1];
            else
               return findMedianById(nums1, l1, h1, nums2, l2, l2 + id - 2, id);
        }
        
        if (h2 - l2 == 0)
        { 
            if (nums1[l1 +id - 1] <= nums2[l2])
               return nums1[l1 + id - 1];
            else
               return findMedianById(nums1, l1, l1 + id - 2, nums2, l2, h2, id);
        }
        
        if (nums1[l1] >= nums2[h2]) 
        {
           if (h2 - l2 + 1 < id)
              return nums1[l1 + id - 1 - (h2 - l2 + 1)];
           else
              return nums2[l2 + id - 1];               
        }
        if (nums2[l2] >= nums1[h1])
        {
           if (h1 - l1 + 1 < id)
              return nums2[l2 + id - 1 - (h1 - l1 + 1)];
           else
              return nums1[l1 + id - 1];   
        } 
        
        int mid1 = (l1 + h1) / 2;
        int mid2 = (l2 + h2) / 2;
        
        int left = mid1 - l1 + 1 + mid2 - l2 + 1;
        if (left < id)
        {  
            if (nums1[mid1] < nums2[mid2])
               return findMedianById(nums1, mid1 + 1, h1, nums2, l2, h2, id - (mid1 - l1 + 1));
            else
               return findMedianById(nums1, l1, h1, nums2, mid2 + 1, h2, id - (mid2 - l2 + 1));
        } 
        else
        {
            if (nums1[mid1] < nums2[mid2])
               return findMedianById(nums1, l1, h1, nums2, l2, mid2, id); 
            else
               return findMedianById(nums1, l1, mid1, nums2, l2, h2, id); 
        }
    }
           
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {           
        int m = nums1.size(), n = nums2.size();
        int id = (m + n - 1) / 2 + 1;
        double median = findMedianById(nums1, 0, m - 1, nums2, 0, n - 1, id);
        if ((m + n) % 2 == 1)
          return median;
        else
        {
            median = median + findMedianById(nums1, 0, m - 1, nums2, 0, n - 1, id + 1); 
            return median / 2.0;   
        }
    }
};

int main()
{
   vector<int> nums1, nums2;
   nums1.clear();
   nums2.clear();
   int x, len1, len2;
   cin >> len1 >> len2;
   while (len1-- > 0)
   {
      cin >> x;
      nums1.push_back(x);
   }
   
   while (len2-- > 0)
   {
      cin >> x;
      nums2.push_back(x);
   }
   
   Solution so;
   double result = so.findMedianSortedArrays(nums1, nums2);
   cout << result << endl;
   system("pause");
   return 0;
}
