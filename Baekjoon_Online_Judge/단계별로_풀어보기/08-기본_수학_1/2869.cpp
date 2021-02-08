//
//  2869.cpp
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
    
    int A, B, V;
    int num = 0;
    
    cin >> A >> B >> V;
    
    num = (V - B - 1) / (A - B) + 1;
    
    cout << num << "\n";
    
    
    return 0;
}
