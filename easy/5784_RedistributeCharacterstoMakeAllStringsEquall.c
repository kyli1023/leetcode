/*************************************************************************
	> File Name: 5784_RedistributeCharacterstoMakeAllStringsEquall.c
	> Author: ky_li
	> Mail: kyli19931023@gmail.com 
	> Created Time: 日  6/13 15:17:54 2021
 ************************************************************************/

#include<stdio.h>
bool makeEqual(char ** words, int wordsSize){
    short count[26];
    memset(count, 0, sizeof(count));
    for (int i = 0; i < wordsSize; i++)
    {
        for (int j = 0; j < strlen(words[i]); j ++)
        {
            count[words[i][j] - 'a'] ++;
        }
    }

    for (int i = 0; i < 26; i ++)
    {
        if (count[i] % wordsSize != 0)
        {
            return false;
        }
    }
    return true;

