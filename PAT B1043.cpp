/*
1043 输出PATest (20 分)
给定一个长度不超过 10 ^ 4 的、仅由英文字母构成的字符串。
请将字符重新调整顺序，按 PATestPATest.... 这样的顺序输出，并忽略其它字符。
当然，六种字符的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按 PATest 的顺序打印，直到所有字符都被输出。

输入格式：
输入在一行中给出一个长度不超过 10 ^ 4 的、仅由英文字母构成的非空字符串。

输出格式：
在一行中按题目要求输出排序后的字符串。题目保证输出非空。

输入样例：
redlesPayBestPATTopTeePHPereatitAPPT

输出样例：
PATestPATestPTetPTePePee
*/
#include <iostream>
#include <cstring>
using namespace std;
char str[10010];
int n[6] = {0};
char s[6] = {'P', 'A', 'T', 'e', 's', 't'};
int main() {
    scanf("%s", str);
    for(int i = 0; str[i]; i++) {
        switch(str[i]) {
            case 'P' : n[0]++;  break;
            case 'A' : n[1]++;  break;
            case 'T' : n[2]++;  break;
            case 'e' : n[3]++;  break;
            case 's' : n[4]++;  break;
            case 't' : n[5]++;  break;
        }
    }
    int t = strlen(str);
    for(int i = 0, j = 0; j < t * 6; i = (i + 1) % 6, j++)
        if(n[i]-- > 0)  printf("%c", s[i]);
    return 0;
}