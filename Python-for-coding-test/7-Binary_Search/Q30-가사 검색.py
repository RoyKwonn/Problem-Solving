def check_word(words, query, checks):
    cnt = 0
    for word in words:
        flag = 1
        if len(word) == len(query):
            for i in checks:
                if word[i] != query[i]:
                    flag = 0
                    break

            if flag == 1:
                cnt += 1

    return cnt


def solution(words, queries):
    answer = []
    # words.sort()
    for i in range(0, len(queries)):
        checks = [] # 와일드카드가 아닌 문자열
        for j in range(0, len(queries[i])):
            if queries[i][j] != '?':
                checks.append(j)

        answer.append(check_word(words, queries[i], checks))

    return answer










words = ["frodo", "front", "frost", "frozen", "frame", "kakao"]
queries = ["fro??", "????o", "fr???", "fro???", "pro?"]
solution(words, queries)



