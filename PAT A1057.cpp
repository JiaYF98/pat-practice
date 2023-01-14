/*
1057 Stack (30 分)
Stack is one of the most fundamental data structures, which is based on the principle of Last In First Out (LIFO). 
The basic operations include Push (inserting an element onto the top position) and Pop (deleting the top element). 
Now you are supposed to implement a stack with an extra operation: PeekMedian -- return the median value of all the elements in the stack. 
With N elements, the median value is defined to be the (N/2)-th smallest element if N is even, or ((N+1)/2)-th if N is odd.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (≤10 ^ ​5). 
Then N lines follow, each contains a command in one of the following 3 formats:

Push key
Pop
PeekMedian
where key is a positive integer no more than 10 ^ 5.

Output Specification:
For each Push command, insert key into the stack and output nothing. 
For each Pop or PeekMedian command, print in a line the corresponding returned value. 
If the command is invalid, print Invalid instead.

Sample Input:
17
Pop
PeekMedian
Push 3
PeekMedian
Push 2
PeekMedian
Push 1
PeekMedian
Pop
Pop
Push 5
Push 4
PeekMedian
Pop
Pop
Pop
Pop

Sample Output:
Invalid
Invalid
3
2
2
1
2
4
4
5
3
Invalid
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define maxsize 100010
struct stack {
    int data[maxsize];
    int top = -1;
};

void Push(stack &s) {
    int x;
    cin >> x;
    s.data[++s.top] = x;
}

void Pop(stack &s) {
    if(s.top == -1)
        cout << "Invalid" << endl;
    else
        cout << s.data[s.top--] << endl;
}

void PeekMedian(stack s) {
    sort(s.data, s.data + s.top + 1);
    int index = (s.top + 2) / 2 - 1;
    if(index < 0 || index > s.top)
        cout << "Invalid" << endl;
    else
        cout << s.data[index] << endl;
}

int main() {
    stack s;
    s.top = -1;
    int n, x;
    cin >> n;
    char str[15];
    for(int i = 0; i < n; i++) {
        cin >> str;
        switch (str[1]) {
            case 'u' :
                Push(s);
                break;
            case 'o' :
                Pop(s);
                break;
            case 'e' :
                PeekMedian(s);
                break;
        }
    }
    return 0;
}