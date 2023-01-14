/*
1052 Linked List Sorting (25 分)
A linked list consists of a series of structures, which are not necessarily adjacent in memory. 
We assume that each structure contains an integer key and a Next pointer to the next structure. 
Now given a linked list, you are supposed to sort the structures according to their key values in increasing order.

Input Specification:
Each input file contains one test case. 
For each case, the first line contains a positive N ( < 10 ^5 ) and an address of the head node, 
where N is the total number of nodes in memory and the address of a node is a 5-digit positive integer. NULL is represented by −1.
Then N lines follow, each describes a node in the format:
Address Key Next
where Address is the address of the node in memory, Key is an integer in [−10 ^ 5, 10 ^ 5], and Next is the address of the next node. 
It is guaranteed that all the keys are distinct and there is no cycle in the linked list starting from the head node.

Output Specification:
For each test case, the output format is the same as that of the input, 
where N is the total number of nodes in the list and all the nodes must be sorted order.

Sample Input:
5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345

Sample Output:
5 12345
12345 -1 00001
00001 0 11111
11111 100 22222
22222 1000 33333
33333 100000 -1
*/

#include <iostream>
#include <algorithm>
using namespace std;

typedef int ElemType;
const int MaxSize = 100010;
struct Node {
    ElemType data;
    int next;
    int flag = 0;
    int address;
} node[MaxSize];

bool cmp(Node a, Node b) {
    if(a.flag != b.flag)
        return a.flag > b.flag;
    else
        return a.data < b.data;
}

int main() {
    int n, begin, address, data, next, count = 0;
    scanf("%d%d", &n, &begin);
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d", &address, &data, &next);
        node[address].address = address;
        node[address].data = data;
        node[address].next = next;
    }
    address = begin;
    while(address != -1) {      //给出的可能有无效地址，应舍去
        node[address].flag = 1;
        count++;
        address = node[address].next;
    }
    if(count == 0) {            //当地址全部无效时
        printf("0 -1");
        return 0;
    }
    sort(node, node + MaxSize, cmp);
    for(int i = 0; i < count - 1; i++) {
        node[i].next  = node[i + 1].address;
    }
    node[count - 1].next = -1;
    printf("%d %05d\n", count, node[0].address);
    for(int i = 0; i < count - 1; i++) {
        printf("%05d %d %05d\n", node[i].address, node[i].data, node[i].next);
    }
    printf("%05d %d %d", node[count - 1].address, node[count - 1].data, node[count - 1].next);
    return 0;
}