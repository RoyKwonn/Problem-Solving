//
//  15596.c
//  Algorithm-Baekjoon
//
//  Created by Seokhwan Kwon on 2021/01/22.
//

#include <stdio.h>

long long sum(int *a, int n) {
    long long ans = 0;
    int i;
    for(i=0; i<n; i++) ans += a[i];
    return ans;
}
