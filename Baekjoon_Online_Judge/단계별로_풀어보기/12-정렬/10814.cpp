//
//  10814.cpp
//  Problem_solving
//
//  Created by Seokhwan Kwon on 2021/02/03.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b)
{
    return a.first < b.first;
}



int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;       // 회원수 입력
    
    pair<int, string> tmp; // 나이, 이름 입력받을 폼 만들기
    
    vector<pair<int, string>> arr;  // 백터형식으로 사용하면 배열보다 느리지만 처리가 쉽다.
    
    for(int i = 0; i < N; i++)
    {
        cin >> tmp.first >> tmp.second;  // 나이, 이름을 입력받아 벡터의 뒤로 넣는다
        arr.push_back(tmp);
    }
    
    // 값이 같은 원소의 전후관계가 바뀌지 않는 정렬 알고리즘을 안정 정렬(stable sort)이라고 합니다.
    stable_sort(arr.begin(), arr.end(), compare);
    
    for(int i = 0; i < N; i++)
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    
    // std::cout << "Hello, World!\n";
    return 0;
}

