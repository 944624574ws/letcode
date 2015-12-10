#include<iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        //int s1 = num, s2 = 0, t;
//        while (1)
//        {
//            if (s1 == 0 && s2 < 10)
//               break;
//               
//            if (s1 == 0 && s2 != 0)
//            {
//               t = s1; s1 = s2; s2 = t;       
//            }
//                        
//            s2 += s1 % 10;
//            s1 = s1 / 10;
//        }
//        return s2;
        int temp = (num - 1) / 9;
        return num - 9 * temp;
    }
};

int main()
{
    int num;
    cin >> num;
    Solution so;
    int result = so.addDigits(num);
    cout << result << endl;
    system("pause");
    return 0;   
}
