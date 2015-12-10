#include<iostream>
#include<cstring>
using namespace std;

class Solution {
public:
    int roman(char c)
    {
        switch(c)
        {
           case 'M': return 1000;
           case 'D': return 500;
           case 'C': return 100;
           case 'L': return 50;
           case 'X': return 10;
           case 'V': return 5;
           case 'I': return 1;         
        }    
    }
    
    int romanToInt(string s) {
        int x, y, sum = 0;
        int i;
        for (i = 0; i < s.length() - 1;)
        {
           x = roman(s[i]);
           y = roman(s[i + 1]);
           if (x < y)
           {
             sum += y - x;
             i = i + 2;
           }
           else
           {
             sum = sum + x;
             ++i;    
           }
        }
        if (i == s.length() - 1)
          sum += roman(s[i]);
        return sum;
    }
};

int main()
{
   string s;
   cin >> s;
   Solution so;
   cout<<so.romanToInt(s)<<endl;
   system("pause");
   return 0;   
}
