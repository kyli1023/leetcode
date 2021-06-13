/*************************************************************************
	> File Name: 1863_SumofAllSubsetXORTotals.c
	> Author: ky_li
	> Mail: kyli19931023@gmail.com 
	> Created Time: 日  6/13 16:26:19 2021
 ************************************************************************/

#include<stdio.h>
int dfs(int *nums, int n, int totalSize, int sum)
{
    if (n == totalSize)
    {
        return sum;
    }
    return dfs(nums, n + 1, totalSize, sum ^ nums[n]) + dfs(nums, n + 1, totalSize, sum);
}

int subsetXORSum(int* nums, int numsSize)
{
    return dfs(nums, 0, numsSize, 0);
}
