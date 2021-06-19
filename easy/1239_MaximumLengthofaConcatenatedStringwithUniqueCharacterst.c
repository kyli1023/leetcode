/*************************************************************************
	> File Name: 1239_MaximumLengthofaConcatenatedStringwithUniqueCharacterst.c
	> Author: ky_li
	> Mail: kyli19931023@gmail.com 
	> Created Time: 六  6/19 18:41:03 2021
 ************************************************************************/

#include<stdio.h>
#define max(a, b) (a) > (b) ? (a) : (b); 
int chk_rep(int *count, char** arr, int n)
{
    for (int i = 0; i < strlen(arr[n]); i ++)
    {
        if(count[arr[n][i] - 'a'] >= 1)
        {
            return true;
        }
    }
    return false;
}

int set_count(int *count, char** arr, int n)
{
    for (int i = 0; i < strlen(arr[n]); i ++)
    {
        if (count[arr[n][i] - 'a'] == 0)
        {
            count[arr[n][i] - 'a'] ++;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void clr_count(int *count, char** arr, int n)
{
    for (int i = 0; i < strlen(arr[n]); i ++)
    {
        count[arr[n][i] - 'a'] = 0;
    }
}

int helper(char **arr, int n, int sum, int arrSize, int *count)
{
    if (n == arrSize)
    {
        return sum;
    }
    if (!chk_rep(count, arr, n))
    {
        int taken, notTaken;
        int temp;
        if (set_count(count, arr, n))
        {
            taken = helper(arr, n + 1, sum + strlen(arr[n]), arrSize, count);
        }
        else
        {
            taken = 0;
        }
        clr_count(count, arr, n);
        notTaken = helper(arr, n + 1, sum, arrSize, count);
        temp = max(taken, notTaken);
        return max(taken, notTaken);
    }
    else
    {
        return helper(arr, n + 1, sum, arrSize, count);
    }
    
}

int maxLength(char ** arr, int arrSize){
    int ans;
    if (arrSize == 1)
    {
        return strlen(arr[0]);
    }
    int count[26] = {0};
    ans = helper(arr, 0, 0, arrSize, count);
    return ans;
}

