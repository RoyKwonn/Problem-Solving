//
//  1712.cpp
//  Problem_solving
//
//  Created by Seokhwan Kwon on 2021/02/08.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    int A, B, C;
    int n = 1;
    
    cin >> A >> B >> C;
    
    if(B >= C) {
        cout << -1;
        return 0;
    }
    
    cout << A/(C-B) + 1;
    
    return 0;
}
