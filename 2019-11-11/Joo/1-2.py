def solution(n):
    ans = 0
    temp_num = n
    while temp_num != 0:
        if (temp_num%2) == 1:
            ans+= 1
            temp_num = temp_num - 1
        temp_num = temp_num/2

    print(ans)
    return ans
