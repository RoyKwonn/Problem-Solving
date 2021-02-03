//
//  10818.c
//  Algorithm-Baekjoon
//
//  Created by Seokhwan Kwon on 2021/01/20.
//

#include <stdio.h>
int main() {
    int N, num;
    int max = -1000001, min = 1000001;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d ", &num);
        if (max < num) max = num;
        if (min > num) min = num;
    }
    printf("%d %d", min, max);
}
