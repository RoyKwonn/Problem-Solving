//
//  10757.cpp
//  Problem_solving
//
//  Created by Seokhwan Kwon on 2021/02/08.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string a, b, result;
    cin >> a >> b;
    
    if(a.size() > b.size())
    {
        string c;
        for(int i = 0; i < a.size() - b.size(); i++) c += '0';
        b = c + b;
    } else {
        string c;
        for(int i = 0; i < b.size() - a.size(); i++) c += '0';
        a = c + a;
    }   // 9999와 1일때 1앞의 3자리에 0 3개를 채우는 문장
    
    int carry = 0;
    while(a.size() != 0 && b.size() != 0)
    {
        int aback = a.back() - '0';     // 문자열에서 맨마지막 문자를 숫자로 바꿈
        int bback = b.back() - '0';     // 마찬가지
        int remain = (carry + aback + bback) % 10;  // 남김수 (9와 1을 더하면 캐리 1 remain 0)
        carry = (carry + aback + bback) / 10; // 올림수
        result = (char)(remain + '0') + result; // 결과 문자열에 합쳐줌
        a.pop_back();
        b.pop_back();
    }
    if(carry) // 마지막 자리까지 다 더했는데 캐리가 있으면 캐리를 맨앞에 붙여줘야함.
        result = (char)(carry + '0') + result;
    cout << result << "\n";
    
    return 0;
}
