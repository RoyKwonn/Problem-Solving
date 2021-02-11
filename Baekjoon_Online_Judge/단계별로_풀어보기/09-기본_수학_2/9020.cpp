//
//  9020.cpp
//  Problem_solving
//
//  Created by Seokhwan Kwon on 2021/02/10.
//

#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    
    int T, N;
    int h, t;
    int check;
    
    cin >> T;
    
    for(int i=0; i<T; i++) {
        h = 0;
        t = 0;
        check = 0;
        
        cin >> N; // 8
        
        h = N/2; // 4
        t = N-h; // 4
        
        while(h > 0) {
            //cout << "h = " << t << " / t = " << t << "\n";
        
            for(int j=2; j<h-1; j++) {
                if(h%j == 0 || t%j == 0) {
                    check++;
                }
            }
            
            //cout << "check =" << check << "\n";
            
            if(check >= 1) {
                h--;
                t++;
                check = 0;
            } else {
                break;
            }
        }
        
        //cout << "result = " << h << " " << t << "\n";
        cout << h << " " << t << "\n";
    }
    
    return 0;
}
