//  Created by Seokhwan Kwon on 2021/07/25.
//
// #include <bits/stdc++.h>


#include <iostream>
#include <string.h>
using namespace std;

int main(void)
{
    int i;
    scanf("%d", &i);
    string str = to_string(i);

    int A = 0, B = 0;

    for(int i = 0; i < str.size()/2; i++)
    {
        A += str[i] - '0';
    }


    for(int i = int(str.size()/2); i < str.size(); i++)
    {
        B += str[i] - '0';
    }

    if (A == B) {
        printf("LUCKY\n");
    } else {
        printf("READY\n");
    }


    return 0;
}
