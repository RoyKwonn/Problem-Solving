//
//  1021.cpp
//  Problem_solving
//
//  Created by Seokhwan Kwon on 2021/02/13.
//

#include <iostream>
#include <deque>
using namespace std;

int main(int argc, const char * argv[])
{
    // IO 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    deque<int> dq;
    
    int arr[50];
    for(int i = 0; i < M; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
    }
    
    for(int i = 1; i <= N; i++)
    {
        dq.push_back(i);
    }
    
    int idx = 0;
    int sum = 0;
    
    while(idx < M)
    {
        deque<int> temp;
        int left = 0;
        int right = 0;
        
        // 왼쪽으로 이동
        while(1)
        {
            if(dq.front() == arr[idx]) break;
            temp.push_back(dq.front());
            dq.pop_front();
            left++;
        }
        
        // 원복
        while(temp.size() != 0)
        {
            dq.push_front(temp.back());
            temp.pop_back();
        }
        
        // 오른쪽
        while(1)
        {
            if(temp.size() != 0 && temp.front() == arr[idx]) break;
            // 오른쪽으로 이동
            int back = dq.back();
            dq.pop_back();
            right++;
            
            // 맨 앞으로 온 값이 원하는 수 인지 check
            temp.push_front(back);
        }
        
        while(temp.size() != 0)
        {
            dq.push_back(temp.front());
            temp.pop_front();
        }
        
        if(left < right)
        {
            sum += left;
            // 왼쪽으로 민다
            
            while(left--)
            {
                int temp = dq.front();
                dq.pop_front();
                dq.push_back(temp);
            }
            dq.pop_front();
        } else {
            sum += right;
            // 오른쪽으로 민다
            while(right--)
            {
                int temp = dq.back();
                dq.pop_back();
                dq.push_front(temp);
            }
            dq.pop_front();
        }
        idx++;
    }
    
    cout << sum << "\n";
    
    return 0;
}
