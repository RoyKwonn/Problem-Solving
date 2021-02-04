//
//  1463.cpp
//  Problem_solving
//
//  Created by Seokhwan Kwon on 2021/02/04.
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;


class make_One{
private:
    int N;      // (1 <= 입력값 <= 10^6)
    int arr [1000001]; // 10^6
public:
    void set_Num(){
        cin >> N;
        memset(arr, 0, sizeof(int) * (N+1));    // 1부터 N까지
    }
    
    // bottom up
    // 1을 빼는 계산부터 시작해서 작은 계산을 통해 미리 arr[i]에 (최대)값을 저장한다.
    // 2로 나누어 떨어지는지, 3으로 나누어 떨어지는지
    // arr[i/2], arr[i/3], arr[i]와 비교하여
    // 그 중 최소값을 arr[i]에 다시 저장한다.
    
    void solution(){
        arr[1] = 0; // 1일땐 횟수가 0이므로 굳이 연산하지 않는다.
        
        for(int i = 2; i <= N; i++) {
            arr[i] = arr[i - 1] + 1;    // 규칙 3번 1을 뺀다. +1을하는건 idx가 0부터시작임
            if(i%2 == 0) {
                arr[i] = min(arr[i], arr[i/2] + 1); // 규칙 2
            }
            
            if(i%3 == 0) {
                arr[i] = min(arr[i], arr[i/3] + 1); // 규칙 1
            }
        }
    }
    
    void print_Min() {
        cout << arr[N];
    }
    
};

int main(int argc, const char * argv[])
{
    //ios_base::sync_with_stdio(false);
    make_One one;
    one.set_Num();
    one.solution();
    one.print_Min();
    
    return 0;
}
