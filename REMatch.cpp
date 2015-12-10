#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class Solution {
public:
    bool complete(string p)
    {
       for (int i = 0; p[i] != '\0'; ++i)
          if (p[i] == '.' || p[i] == '*')
             return false;
       return true;     
    }
      
    bool strcmp(string s1, string s2)
    {
       int i;
       for (i = 0; s1[i] != '\0' && s2[i] != '\0'; ++i)
          if (s1[i] != s2[i])
            return false;
       if (s1[i] == '\0' && s2[i] == '\0')
          return true;
       else
          return false;  
    }
       
    bool isMatch(string s, string p) {
        if (complete(p))
        {
           if (strcmp(s, p))
              return true;
           else
              return false;                
        }
        int i, j;
        for (i = 0, j = 0; s[i] != '\0' && p[j] != '\0';)
        {
          if (p[j] == '.')
          {  
              ++i;
              ++j;
          }
          else if (p[j] == '*')
          {
              if (j == 0 || p[j - 1] == '.')
                 ++i;
              else
              {
                 if (s[i] == p[j - 1])
                    ++i;
                 else
                    ++j;
              }
          }
          else if (s[i] != p[j])
          {
             if (p[j + 1] == '*')
                j = j + 2;
             else
                return false;
          }
          else
          {
             ++i;
             ++j;    
          }
        }  
        
        if (s[i] != '\0')
           return false;
        if (p[j] != '\0')
        {
           if (p[j + 1] == '\0' &&  p[j] == '*')
              return true;
           else
              return false;
        }
        if (s[i] == '\0' && p[j] == '\0')
           return true;
    }
};

int main()
{
   
   Solution so;
   cout<<so.isMatch("aaa", "a*a")<<endl;
   system("pause");
   return 0;   
}
