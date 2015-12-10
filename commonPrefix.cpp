#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
          return "";
        int min = INT_MAX;
        for (int i = 0; i < strs.size(); ++i)
          if (strs[i].length() < min)
             min = strs[i].length();
        int i;
        for (i = 0; i < min; ++i)
        {
            char x = strs[0][i];
            int j;
            for (j = 1; j < strs.size(); ++j)
               if (strs[j][i] != x)
                  break;
            if (j < strs.size())
              break;   
        }
        return strs[0].substr(0, i);
    }
};

int main()
{
   
   string x;
   int n;
   cin >> n;
   vector<string> str(n, "");
   for (int i = 0; i < n; ++i)
   {
      cin >> x;
      str[i] = x;   
   }
   Solution so;
   string res = so.longestCommonPrefix(str);
   cout<<res;
   system("pause");
   return 0;   
}
