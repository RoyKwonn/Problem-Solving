//
//  15651.cpp
//  Problem_solving
//
//  Created by Seokhwan Kwon on 2021/02/03.
//

#include <iostream>
using namespace std;

// 첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 7)
const int MAX = 7;

int N, M;
int arr[MAX];

void func(int idx)
{
    if(idx == M) // 0을 고를경우와 최대치에 도달한 경우 포함
    {
        for(int i = 0; i < M; i++) // 0일경우 skip
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i = 1; i <= N; i++)
    {
        arr[idx] = i; // 1부터 수가 시작함은 수열의 시작도 1이기 때문이다.
        // 재귀적 호출로 차곡차곡 global arr에 M까지의 최대수를 입력해준다.
        func(idx + 1);
    }
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    // C를 이 C++ 코드에 동기화하지 않겠다는 선언
    // 속도향상을 위함, (wyh> 쓰레드를 사용할때, race condition을 발생하지 않아서 버퍼사용을 독립적으로 할 수 있다.
    
    cin.tie(0);
    // I/O 작업전에 자동으로 flush(콘솔에 표시)하는 것을 멈추겠다는 선언
    // 즉 CIN과 COUT은 사실 연결되어 있다.
    
    cin >> N >> M;
    
    func(0);
    
    return 0;
}
