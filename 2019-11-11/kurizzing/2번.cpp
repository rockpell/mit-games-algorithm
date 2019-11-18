#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;

    while(n > 0)
    {
        if(n % 2 != 0)  //2로 나누어지지 않을 때
        {
            n--;
            ans++;
        }
        n /= 2;
    }

    return ans;
}