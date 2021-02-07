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
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    int n;
    stack<int> st;
    vector<int> v;
    vector<char> d;
    cin >> n;
        
    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        v.push_back(k);
    }
    
    vector<int>::iterator it;
    it = v.begin();
    
    for(int i = 1; i <= n; i++) {
        st.push(i);
        d.push_back('+');
        while(!st.empty())
        {
            if(*it != st.top()) break;
            else {
                st.pop();
                d.push_back('-');
                ++it;
            }
        }
    }
    if(st.empty()) {
        for(int i=0; i < d.size(); ++i)
        {
            cout << d[i] << "\n";
        }
    } else {
        cout << "NO";
    }

    return 0;
}
