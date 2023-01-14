/*
1093 Count PAT's (25 分)
The string APPAPT contains two PAT's as substrings. 
The first one is formed by the 2nd, the 4th, and the 6th characters, and the second one is formed by the 3rd, the 4th, and the 6th characters.

Now given any string, you are supposed to tell the number of PAT's contained in the string.

Input Specification:
Each input file contains one test case. 
For each case, there is only one line giving a string of no more than 10 ^ 5 characters containing only P, A, or T.

Output Specification:
For each test case, print in one line the number of PAT's contained in the string. 
Since the result may be a huge number, you only have to output the result moded by 1000000007.

Sample Input:
APPAPT
Sample Output:
2
*/
#include <iostream>
#include <cstring>
using namespace std;
const int mod = 1000000007;
char str[100010];
int p[100010] = {0};
int t = 0;
int main() {
    scanf("%s", str);
    int len = strlen(str);
    int sum = 0;
    for(int i = 0; i < len; i++) {
        if(i)   p[i] = p[i - 1];
        if(str[i] == 'P')   p[i]++;
    }
    for(int i = len - 1; i >= 0; i--) {
        if(str[i] == 'T')   t++;
        else if(str[i] == 'A')  sum = (sum + p[i] * t) % mod;   //此处不取余 有可能越界
    }
    printf("%d", sum);
    return 0;
}