#include <iostream>
using namespace std;
char str[10000];
int main() {
    FILE *fp = fopen("test.txt", "w");
    if(fp == NULL) {
        printf("打开文件失败！");
        exit(0);
    }
    cin.getline(str,sizeof(str));
    for(int i = 0; i < 10000; i++) {
        fputs(str, fp);
        fputs("\n", fp);
    }
    fclose(fp);
    return 0;
}