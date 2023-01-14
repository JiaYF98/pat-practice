/*
1013 数素数 (20 分)
令 Pi 表示第 i 个素数。现任给两个正整数 M ≤ N ≤ 10 ^ ​4，请输出 P​M 到 PN 的所有素数。

输入格式：
输入在一行中给出 M 和 N，其间以空格分隔。

输出格式：
输出从 P​M 到 P​N 的所有素数，每 10 个数字占 1 行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27

输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/
#include <iostream>
using namespace std;
bool isPrime[1000000];
int Prime[10010];
int main() {
    int M, N;
    for(int i = 2; i <= 1000000; i++)
        isPrime[i] = true;
    for(int i = 2; i <= 1000000; i++) {
        if(isPrime[i])
            for(int j = i * 2; j < 1000000; j += i)
                isPrime[j] = false;
    }
    int t = 1;
    for(int i = 2; i <= 1000000 && t < 10010; i++)
        if(isPrime[i])
            Prime[t++] = i;
    scanf("%d%d", &M, &N);
    int k = 0;
    for(int i = M; i < N + 1; i++) {
        if(k == 0)  printf("%d", Prime[i]);
        else printf(" %d", Prime[i]);
        k = (k + 1) % 10;
        if(k == 0)  printf("\n");
    }
    return 0;
}