/*
1025 PAT Ranking (25 分)
Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. 
Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. 
Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive number N (≤100), the number of test locations. 
Then N ranklists follow, each starts with a line containing a positive integer K (≤300), 
the number of testees, and then K lines containing the registration number (a 13-digit number) and the total score of each testee. 
All the numbers in a line are separated by a space.

Output Specification:
For each test case, first print in one line the total number of testees. Then print the final ranklist in the following format:

registration_number final_rank location_number local_rank

The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of the final ranks. 
The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.

Sample Input:
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85

Sample Output:
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct testee {
    char registration_number[14];
    int score;
    int final_rank;
    int location_number;
    int local_rank;

} testees[30010];


bool cmp(testee a, testee b) {
    if(a.score != b.score) return a.score > b.score;    //if的判定条件不能写a.score > b.score
    else return strcmp(a.registration_number, b.registration_number) < 0;   //注意对字符串排序不能直接用'>'和'<'比较
    /*
    如果用a.registration_number < b.registration_number 则下面用例不排序：
    2
    5
    1234567890001 95
    1234567890005 95
    1234567890003 95
    1234567890002 95
    1234567890004 95
    4
    1234567890013 95
    1234567890011 95
    1234567890014 95
    1234567890012 95
    */
}

void local_rank_sort(testee a[], int num) {
    a[0].local_rank = 1;
    for(int i = 1; i < num; i++) {
        if(a[i].score == a[i - 1].score)    a[i].local_rank = a[i - 1].local_rank;
        else a[i].local_rank = i + 1;
    }
}

void final_rank_sort(testee a[], int num) {
    a[0].final_rank = 1;
    for(int i = 1; i < num; i++) {
        if(a[i].score == a[i - 1].score)    a[i].final_rank = a[i - 1].final_rank;
        else a[i].final_rank = i + 1;
    }
}

int main() {
    int N, K;
    int location_number = 0, sum = 0;
    scanf("%d", &N);
    int num[N];
    for(int i = 0; i < N; i++) {
        location_number++;
        scanf("%d", &K);
        num[i] = K;
        for(int j = 0; j < K; j++) {
            sum++;
            scanf("%s %d", &testees[sum - 1].registration_number, &testees[sum - 1].score);
            testees[sum - 1].location_number = location_number;
        }
    }
    
    int numsum = 0;
    for(int i = 0; i < N; i++) {
        sort(testees + numsum, testees + numsum + num[i], cmp);
        local_rank_sort(testees + numsum, num[i]);
        numsum += num[i];
    }

    sort(testees, testees + sum, cmp);
    final_rank_sort(testees, sum);

    printf("%d\n", sum);
    for(int i = 0; i < sum; i++) {
        printf("%s %d %d %d\n", testees[i].registration_number, testees[i].final_rank, testees[i].location_number, testees[i].local_rank);
    }

    return 0;
}

/*
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct testee {
    char registration_number[14];
    int score;
    int location_number;
    int local_rank;

} testees[30010];
bool cmp(testee a, testee b) {
    return a.score != b.score ? a.score > b.score : strcmp(a.registration_number, b.registration_number) < 0;
}

int main() {
    int n, k, num = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &k);
        for(int j = 0; j < k; j++) {
            scanf("%s %d", &testees[num].registration_number, &testees[num].score);
            testees[num].location_number = i + 1;
            num++;
        }
        sort(testees + num - k, testees + num, cmp);
        testees[num - k].local_rank = 1;
        for(int j = num - k + 1; j < num; j++) 
            testees[j].score == testees[j - 1].score ? testees[j].local_rank = testees[j - 1].local_rank : testees[j].local_rank = j - (num - k) + 1;
    }
    printf("%d\n", num);
    sort(testees, testees + num, cmp);
    int r = 1;
    for(int i = 0; i < num; i++) {
        if(i > 0 && testees[i].score != testees[i - 1].score) {
            r = i + 1;
        }
        printf("%s %d %d %d\n", testees[i].registration_number, r, testees[i].location_number, testees[i].local_rank);
    }
    return 0;
}
*/