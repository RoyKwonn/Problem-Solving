//
//  2292.cpp
//  Problem_solving
//
//  Created by Seokhwan Kwon on 2021/02/08.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(false);
    
    int number;
    cin >> number;
    
    int i = 0;
    
    for(int sum = 2; sum <= number; i++)
    {
        sum += 6*i;
    }
    
    if(number == 1) i = 1;
    cout << i;
    
    return 0;
}
