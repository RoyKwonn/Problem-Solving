//
//  2108.cpp
//  Algorithm-Baekjoon
//
//  Created by Seokhwan Kwon on 2021/02/01.
//

#include <iostream>
#include <algorithm>    // for sort()
#include <vector>       // for vector<>
#include <cmath>        // for round()
using namespace std;


vector<int> arr;


int main() {

    int N         // 수의 개수
    int tmp         // 임시
    int mean = 0;   // 1. 산술평균
    int middle = 0  // 2. 중앙값
    int most_val    // 3. 최빈값
    int range       // 4. 범위
    
    
    int most = -9999;
    int number[8001] = {0,};    // 절대값이 4000을 넘지 않는다는 것은 범위가 (-4000, ..., 0, ..., 4000)이다 따라서 8001크기의 배열을 선언하였다.
    bool not_first = false;
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> tmp;             // 정수를 입력받는다 (절대값이 4000을 넘지 않는다)
        arr.push_back(tmp);     // 입력된 정수를 차례대로 arr 뒤로 넣는다.
        mean += tmp;            // 산술평균을 만들기 위하여 입력된 값들의 합을 mean에 넣는다.
        number[tmp+4000]++;     // 각 배열로 사용된 수들을 알 수 있도록 ++연산을 하였다.
    }
    
    sort(arr.begin(),arr.end());    // 4. 범위를 출력하기 위함
    // sort의 첫번째 인자는 시작지점을, 두번째인자는 끝지점을 주는것(배열도 유사하다)
    // default는 오름차순으로 정렬된다.
    
    // 3. 최빈값 구하기
    for(int i = 0; i < 8001; i++)
    {
        if(number[i] == 0)  // 사용된 수가 없다면,
            continue;
        if(number[i] == most)   // 최빈값이 동일한게 나온다면?
        {
            if(not_first) // 동일한게 나온다면, 발견된 최빈값중 두번째로 작은걸 표시하기 위함이다.
            {
                most_val = i - 4000;
                not_first = false; // 발견되지 않은 것처럼 표시한다.
            }
        }
        if(number[i] > most) // 현재 발견된 것들 중 최빈값이라면?
        {
            most = number[i];
            most_val = i - 4000;    // 절대값을 벗긴 수
            not_first = true;       // 최빈값을 발견한 티내기
        }
    }
    
    mean = round((float)mean / num);    // 1. 산술평균 (소수점 이하 첫째 자리에서 반올림)
    middle = arr[arr.size()/2];         // 2. 중앙값
                                        // 3. 위에서 최빈값을 구했다.
    range = arr.back() - arr.front();   // 4. 범위를 출력한다.
    
    cout << mean << '\n' << middle << '\n' << most_val << '\n' << range;
}
