def solution(record):
    answer = []
    dic = {}
    split_record = list()
    record_len = len(record)  ## 문자열의 갯수 
    for i in range(0, record_len):
        split_record.append(record[i].split(' '))
        if split_record[i][0] != "Leave":
            dic[split_record[i][1]] = split_record[i][2]    ## uid key에 닉네임을 value로 저장함 


    for i in range(0, record_len):  ## 명령어에 따라서 출력
        if(split_record[i][0] == "Enter"):
            answer.append(dic.get(split_record[i][1])+"님이 들어왔습니다.")
        elif(split_record[i][0] == "Leave"):
            answer.append(dic.get(split_record[i][1])+"님이 나갔습니다.")

##    print(answer)
    return answer
