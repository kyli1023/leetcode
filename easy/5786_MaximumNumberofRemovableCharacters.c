/*************************************************************************
	> File Name: 5786_MaximumNumberofRemovableCharacters.c
	> Author: ky_li
	> Mail: kyli19931023@gmail.com 
	> Created Time: 日  6/13 14:58:34 2021
 ************************************************************************/

#include<stdio.h>

char del[100001];

void removeChar(int *arr, int idx)
{
   for(int i = 0; i <= idx; i ++) 
   {
       del[arr[i]] = 1;     // 用mark 的方式代替刪除
   }
}

int chk(char* s1, char* s2, int* arr, int k)  // chk s2 是否是s1 的子字串
{
    memset(del, 0, sizeof(del));
    removeChar(arr, k);
    for(int i = 0; *s1 != '\0'; i++, s1++) 
    {
        if (del[i] == 1)
            continue;
        if (*s1 == *s2)
        {
            s2++;
            if (*s2 == '\0')
                return true;
        }
    }
    return false;
}

int maximumRemovals(char * s, char * p, int* arr, int size){
    int l = 0; 
    int r = size;
    int m;
    int ans = 0;
    while (l < r)              //solution 1 - 個人很不喜歡這樣寫，因為老是搞不清楚到底要return 誰， 或者是 l < r or l <= r? 常常需要想邊界條件
    {
        m = (r + l) / 2;
        if (chk(s, p, arr, m))
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }
    ans = r;
    /*
    int k = -1;                              // solution 2 - 會找到第一個符合條件的人  =》 k ， 單方向簡單很多，也是100% faster
    for (int j = (r + l) / 2; j > 0; j >>= 1)
    {
        while (((j + k) < size) && chk(s, p, arr, k + j))
        {
            k += j;
        }
    }     
    ans = k + 1; // 1 base
    */
    return ans;
}

