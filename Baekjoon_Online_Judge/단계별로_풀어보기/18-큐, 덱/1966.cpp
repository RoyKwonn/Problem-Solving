//
//  1966.cpp
//  Problem_solving
//
//  Created by Seokhwan Kwon on 2021/02/08.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[])
{
    int t, n, m; // n=문서의 수 // m=궁금한 문서가 Queue의 어느 위치에 있는지
        int cnt; // 그 순간의 출력 순서
        queue< pair<int, bool>> q; // <우선순위, m번째 수인지의 여부(맞다면 true)
        cin >> t;
        
        for (int i = 0; i < t; i++) {
            cin >> n >> m;
            vector<int> doc(n); // 우선순위 비교를 위해 큐의 숫자들을 따로 저장해두는 벡터
            for (int i = 0; i < n; i++) {
                cin >> doc[i];
                if (i != m) {
                    q.push({ doc[i], false });
                }
                else {
                    q.push({ doc[i], true });
                }
            }
            
            sort(doc.begin(), doc.end()); // doc는 오름차순으로 정렬
            cnt = 1;
            while (1) {
                if (q.front().first == doc[doc.size()-1]) { // 맨 앞의 문서가 현재 가장 우선순위가 높은 문서라면
                    if (q.front().second) { // 그리고 그 문서가 처음에 m번째 문서였다면
                        break; // 반복문을 끝내고 cnt 출력할 준비
                    }
                    else { // m번째 문서가 아니라면
                        q.pop(); // ABCD -> BCD
                    }
                    cnt++;
                    doc.erase(doc.begin()+doc.size()-1);
                }
                else {
                    q.push(q.front()); // 맨 앞 문서를 맨 뒤로 push
                    q.pop(); // ABCDA -> BCDA
                }
            }
            cout << cnt << "\n";
            while (!q.empty()) q.pop(); // q 초기화
    }
    
    return 0;
}
