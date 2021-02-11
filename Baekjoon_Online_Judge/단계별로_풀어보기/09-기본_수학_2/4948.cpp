//
//  4948.cpp
//  Problem_solving
//
//  Created by Seokhwan Kwon on 2021/02/10.
//


// 베르트랑 공준은 임의의 자연수 n에 대하여, n보다 크고, 2n보다 작거나 같은 소수는 적어도 하나 존재한다는 내용을 담고있다.
// 이 명제는 조제프 베르트랑이 1845년에 추측했고, 파프누티 체비쇼프가 1850년에 증명했다.
// 예를 들어, 10보다 크고, 20보다 작거나 작은 소수는 4개가 있다.
// (11, 13, 17, 19) 또, 14보다 크고, 28보다 작거나 같은 소수는 3개가 있다. (17, 19, 23)
// 자연수 n이 주어졌을 때, n보다 크고, 2n보다 작거나 같은 소수의 개수를 구하는 프로그램을 작성하시오.

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main(void)
{
    int n;
    int cnt = 0;
    int max = 0;
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    vector<int> vec;

    while (1)
    {
        cin >> n;
        if (n == 0) break;
        vec.push_back(n);
        if (max < n) max = n;
    }

    int* arr = new int[2 * max + 1];
    
    fill(arr, arr + (2 * max + 1), 1);
    
    arr[0] = 0;
    arr[1] = 0;

    for (int i = 2; i < 2 * max + 1; i++)
    {
        if (arr[i] == 0) continue;
        for (int j = i + i; j < 2 * max + 1; j = j + i)
            arr[j] = 0;
    }
    
    for (int j = 0; j < vec.size(); j++)
    {
        cnt = 0;
        for (int i = vec[j] + 1; i <= 2 * vec[j]; i++) {
            if (arr[i] == 1) cnt++;
        }
        cout << cnt << "\n";
    }

    delete[] arr;

    return 0;
}
