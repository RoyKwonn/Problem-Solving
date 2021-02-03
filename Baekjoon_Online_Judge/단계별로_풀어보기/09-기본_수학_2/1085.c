//
//  1085.c
//  Algorithm-Baekjoon
//
//  Created by Seokhwan Kwon on 2021/01/26.
//

#include <stdio.h>

// 직사각형이라 이렇게 가능하다.
// 뭐.. 양쪽방향으로 거리가 같다면 둘다 답 아니겠는가?
// 이렇게만 해도 풀리는데 문제 없다.
int min_Distance(int *arr, int size)
{
    int i, min_d = arr[0]; // 초기값 아무거나 잡자
    
    for(i = 0; i < size; i++)
    {
        if(arr[i] < min_d)
            min_d = arr[i];
    }
    
    return min_d;
}

int main()
{
    int w, h; // 직사각형의 가로, 세로
    int arr[4]; // 상하좌우 표시
    
    scanf("%d %d %d %d", &arr[0], &arr[1], &w, &h);
    
    arr[2] = w - arr[0];
    arr[3] = h - arr[1];
    
    printf("%d\n", min_Distance(arr, 4));
    
    return 0;
}
