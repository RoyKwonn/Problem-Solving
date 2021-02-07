//
//  1010.cpp
//  Problem_solving
//
//  Created by Seokhwan Kwon on 2021/02/07.
//

#include <iostream>
using namespace std;


// 조합 문제임 (Combination)
// M개중에 N개를 순서상관없이 뽑는 문제
int main(int argc, const char * argv[])
{
    // 속도 빨라지게 하기위한 얌생이
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    int N, M, T;
    cin >> T;
    long long ans;
    
    while(T--)  // T번 반복
    {
        ans = 1;
        cin >> N >> M; // mCn
        
        if(N > (M/2)){  // 더 작은수로 바꾸어 주기
                        // 연산수 줄이기 위함
            N = (M - N);
        }
        
        // (M - N)!  / N!
        for(int i = 0; i < N; i++) {
            ans *= (M - i); // = mPn
        }
        
        for(int i = 0; i < N; i++) {
            ans /= (i + 1); // n!으로 (순서)
        }
        cout << ans << "\n";
    }
    
    return 0;
}
