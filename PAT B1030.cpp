/*
给定一个正整数数列，和正整数 p，设这个数列中的最大值是 M，最小值是 m，如果 M≤mp，则称这个数列是完美数列。

现在给定参数 p 和一些正整数，请你从中选择尽可能多的数构成一个完美数列。

输入格式：
输入第一行给出两个正整数 N 和 p，其中 N（≤10^5）是输入的正整数的个数，p（≤10^9）是给定的参数。第二行给出 N 个正整数，每个数不超过 10^9。

输出格式：
在一行中输出最多可以选择多少个数可以用它们组成一个完美数列。

输入样例：
10 8
2 3 20 4 5 1 6 7 8 9
输出样例：
8
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int nums[100010];
    int N;
    long p;
    cin >> N >> p;

    int size = 0;
    int currentSize = 0;

    // 输入数组
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    sort(nums, nums + N);
    
    long m = nums[0];
    long M = nums[0];

    int left = 0;
    int right = 0;

    // 双指针
    while (left < N)
    {
        while (M > m * p) {
            // 更新最小值
            m = nums[++left];
            currentSize--;
        }

        while (right < N)
        {
            // 更新最大值
            M = nums[right];

            if (M <= m * p)
            {
                currentSize++;
                right++;
            }
            else
            {
                if (currentSize > size)
                    size = currentSize;
                break;
            }
        }

        if (right == N) {
            break;
        }

    }

    cout << max(currentSize, size) << endl;
}
