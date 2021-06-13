/*************************************************************************
	> File Name: 5786_MaximumNumberofRemovableCharacters.c
	> Author: ky_li
	> Mail: kyli19931023@gmail.com 
	> Created Time: 日  6/13 14:58:34 2021
 ************************************************************************/

#include<stdio.h>


int maximumRemovals(char * s, char * p, int* arr, int size){
    int l = 0;
    int r = size;
    int m;
    int ans = 0;
    while (l < r)
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
    int k = 0;
    for (int j = (r + l) / 2; j > 0; j >>= 1)
    {
        while (((j + k) < size) && chk(s, p, arr, k + j))
        {
            k += j;
        }
    }
    if (chk(s, p, arr, k))
        ans = k + 1; // 1 base
    */
    return ans;
}

