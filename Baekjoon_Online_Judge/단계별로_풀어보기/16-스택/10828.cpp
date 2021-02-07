//
//  10828.cpp
//  Problem_solving
//
//  Created by Seokhwan Kwon on 2021/02/08.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    stack<int> st; // int type의 stack 선언.
    string str;
    
    for(int i=0; i<N; i++)
    {
        cin >> str;
        
        if(str == "push") {
            int num;
            cin >> num;
            st.push(num);
        } else if(str == "pop") {
            if(!st.empty()) {
                cout << st.top() << "\n";
                st.pop();
            } else {
                cout << "-1" << "\n";
            }
        } else if(str == "size") {
            cout << st.size() << "\n";
        } else if(str == "empty") {
            if(st.empty()) {
                cout << "1" << "\n";
            } else {
                cout << "0" << "\n";
            }
        } else if (str == "top") {
            if(!st.empty()) {
                cout << st.top() << "\n";
            } else {
                cout << "-1" << "\n";
            }
        }
    }
    
    return 0;
}
