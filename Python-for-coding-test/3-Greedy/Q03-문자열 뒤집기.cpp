//  Created by Seokhwan Kwon on 2021/07/25.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0; i < s.size()-1; i++) {
        if(s[i] != s[i+1]) {
            cnt++;
        }
    }
    
    
    printf("%d\n",  (cnt+1) / 2); // 미리 더해놓고 계산하는것이 편하네
    
    return 0;
}

