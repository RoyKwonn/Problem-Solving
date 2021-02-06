//
//  1065.cpp
//  Problem_solving
//
//  Created by Seokhwan Kwon on 2021/02/06.
//

#include <iostream>
#include <string>
using namespace std;


// 한수 : 어떤 양의 정수 X의 각 자리가 등차수열

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(false);
    
    int N, res = 0;
    cin >> N;
    

    // (1 < X < N)
    for(int i = 1; i <= N; i++)
    {
        string cur = to_string(i);
        int size = cur.size(); // 수가 한자리 i가 알아본다.
        
        if(size == 1) res += 1; // 만약 한자리 수면 등차수열이 가능하다고 본다.
        else { // 두자리수 일경우
            int seq = cur.at(1) - cur.at(0);  // (10^1 자리수 파악) 앞자리에서 뒷자리를 뺀다.
            bool flag = true;
            
            for(int j = 1; j < size - 1; j++){ // (10^j자리수 파악
                int cur_seq = cur.at(j+1) - cur.at(j);
                    
                if(cur_seq != seq){ // 앞에서 비교한 값과 다르면 등차가 아니다.
                    flag = false;
                    break;
                }
                
            }
            if(flag){
                res += 1;
            }
        }
    }
                cout << res <<'\n';
    
    return 0;
}
