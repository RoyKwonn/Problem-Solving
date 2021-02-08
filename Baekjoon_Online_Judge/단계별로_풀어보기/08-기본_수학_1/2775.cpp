//
//  2775.cpp
//  Problem_solving
//
//  Created by Seokhwan Kwon on 2021/02/08.
//

#include <iostream>
#define MAX 15
using namespace std;


int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
        
    int arr[MAX][MAX];
    arr[0][0] = 1;
    
    for(int i = 1; i < MAX; i++)
    {
        arr[0][i] = i+1;
        arr[i][0] = 1;
    }
    
    for(int i = 1; i < MAX; i++)
    {
        for(int j = 1; j < MAX; j++)
        {
            arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
        }
    }
    
    int size, n, k;
    cin >> size;
    for(int i = 0; i < size; i++)
    {
        cin >> n >> k;
        cout << arr[n][k - 1] << "\n";
    }
 
    return 0;
}
