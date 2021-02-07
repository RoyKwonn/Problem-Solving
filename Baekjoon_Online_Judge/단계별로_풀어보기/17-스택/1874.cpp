//
//  1874.cpp
//  Problem_solving
//
//  Created by Seokhwan Kwon on 2021/02/08.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(int argc, const char * argv[])
{
    // 얌생이 내용
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    
    
    int n;
    stack<int> st;  // 스택
    vector<int> v;  // 입력된 수를 차례대로 저장
    vector<char> ans; // 연산 결과를 내는 기호
    cin >> n;
    
    
    
    // 우선 숫자를 차례대로 받기
    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        v.push_back(k);
    }
    
    vector<int>::iterator it; // 반복자 설정
    it = v.begin();
    
    // n개에 대한 차례대로 설정하기
    for(int i = 0; i < n; i++)
    {
        // push할땐 '+'
        st.push(i);
        ans.push_back('+');
        
        // 스택안에 값이 있다면?
        while(!st.empty())
        {
            // it에 v의 첫번째값이 저장되어 있다.
            if(*it != st.top()) break; // 값이 같다면 pop을하지 않는다.
            else {
                st.pop();
                ans.push_back('-'); // pop할때는 '-'
                ++it;
            }
        }
    }
    if(st.empty()) {
        for(int i=0; i < ans.size(); ++i)
        {
            // 저장된 문자들을 불러온다.
            cout << ans[i] << "\n";
        }
    } else {
        cout << "NO";
    }

    return 0;
}
