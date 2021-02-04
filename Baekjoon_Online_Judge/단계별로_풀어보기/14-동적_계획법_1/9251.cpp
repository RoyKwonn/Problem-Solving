//
//  9251.cpp
//  Problem_solving
//
//  Created by Seokhwan Kwon on 2021/02/04.
//


#include <algorithm>
#include <cstdio>
using namespace std;

char s1[1002], s2[1002]; // 최대 1000글자 + 1(NULL)
int dp[1001][1001], i, j;

int main(int argc, const char * argv[])
{
    scanf("%s %s", s1 + 1, s2 + 1);
        for (i = 1; s1[i]; i++)
            for (j = 1; s2[j]; j++)
                dp[i][j] = max({ dp[i][j - 1], dp[i - 1][j],
                                 dp[i - 1][j - 1] + (s1[i] == s2[j])
                               });
        printf("%d", dp[i - 1][j - 1]);
        return 0;
}
