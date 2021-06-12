/*************************************************************************
	> File Name: 278_FirstBadVersion.c
	> Author: ky_li
	> Mail: kyli19931023@gmail.com 
	> Created Time: 日  6/13 02:45:22 2021
 ************************************************************************/

#include<stdio.h>
#define FIRST_SOL 1

#if FIRST_SOL == 1
int firstBadVersion(int n) {
    int l = 0, r = n;
    while (l < r)
    {
        int m = l + (r - l) / 2;  // 避免 overflow
        if (isBadVersion(m))
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    return l;
}
#else
typedef long long ll;
int firstBadVersion(int n) {
    int m = n / 2;
    int k = 0;
    for (ll j = m; j > 0; j >>= 1)
    {
        while ((k + j < n) && (isBadVersion(k + j) == false)) // k + j 會overflow 要宣告成long long 
        {
            k += j;
        }
    }
    return k + 1; //會找到最後一個false，+1即可得到第一個true
}
#endif

