//
//  7568.cpp
//  Algorithm-Baekjoon
//
//  Created by Seokhwan Kwon on 2021/01/29.
//

#include<iostream>
using namespace std;
 
// global 변수로 선언됨
pair<int, int>people[50]; // 몸무게, 키를 묶어준다.

int Rank[50];
 
void compareRank(const int N) { // 고정된 상수로 받는다
    
    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < N;j++)
        {
            // 각각 i보다 스스로가 큰지 작은지를 비교하여 등수를 매긴다.
            if (people[i].first > people[j].first && people[i].second > people[j].second)
                Rank[j]++;
        }
    }
}
 
void printRank(const int N) {
    for (int i = 0;i < N;i++) {
        cout << Rank[i] + 1 << " "; // compareRank에서 확인한 랭크를 출력한다.
    }
}
 
int main() {
    int N;
    cin >> N; // 처음에 입력되는 전체 인원수
    
    
    for (int i = 0;i < N;i++) {
        cin >> people[i].first >> people[i].second; // 각각 데이터 값을 입력해준다.
    }
 
    compareRank(N); // 등수 비교
    printRank(N);
 
    return 0;
}
