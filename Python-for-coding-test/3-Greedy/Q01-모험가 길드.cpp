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
    
    int n;
    vector<int> v;
    int cnt = 0;
    int result = 0;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0; i<n; i++) {
        cnt++;
        if(cnt>= v[i]) {
            cnt = 0;
            result++;
        }
    }
    
    printf("%d\n", result);
    
    return 0;
}

