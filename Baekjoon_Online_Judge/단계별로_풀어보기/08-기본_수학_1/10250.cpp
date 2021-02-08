//
//  10250.cpp
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
    
    int T;
    cin >> T;
    int H, W, N;
    
    for(int i = 0; i < T; i++)
    {
        cin >> H >> W >> N;
        int H1, W1;
        H1 = N%H;
        W1 = N/H;
        if(H1 > 0)
            W1++;
        else
            H1 = H;
        cout << H1 * 100 + W1 << "\n";
    }
    
    return 0;
}
