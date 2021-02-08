//
//  1193.cpp
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
    
    long long X; cin >> X;
    long long num = 1;
    
    while (X > num) {
        X -= num;
        num++;
    }
    
    if(num % 2) {
        cout << num + 1 - X << '/' << X << '\n';
    } else {
        cout << X << '/' << num + 1 - X << '\n';
    }
    
    return 0;
}
