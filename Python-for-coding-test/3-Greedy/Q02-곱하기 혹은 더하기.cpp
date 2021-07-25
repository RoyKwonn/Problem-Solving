//
//  main.cpp
//  TEMP
//
//  Created by Seokhwan Kwon on 2021/07/25.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    
    string s;
    cin >> s;
    int result = 0;
    for(int i=0; i<s.size(); i++) {
        int x = s[i] - '0';
        if(x<=1) {
            result += x;
        }
        else {
            if(result <= 1) {
                result += x;
            }
            else {
                result *= x;
            }
        }
    }
    
    cout << result << '\n';
    
    return 0;
}

