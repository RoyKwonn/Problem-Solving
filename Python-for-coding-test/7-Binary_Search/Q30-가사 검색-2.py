
def solution(words, queries):
    result = []
    for query in queries:
        answer = 0
        length = len(query)
        # 맨 앞글자가 ?인 경우
        if query[0] == "?":
            # 문자열을 뒤집는다
            query = query[::-1]
            # 필요한 문자열만 취한 뒤 다시 뒤집는다
            prefix = query.split("?")[0][::-1]
            for value in words:
                # prefix가 0이면, 단어 길이만 같을 경우 전부 포함된다
                if len(prefix) == 0 and len(value) == length:
                    answer += 1
                elif value.endswith(prefix) and len(value) == length:
                    answer += 1
            result.append(answer)
        else:
            prefix = query.split("?")[0]
            for value in words:
                if len(prefix) == 0 and len(value) == length:
                    answer += 1
                elif value.startswith(prefix) and len(value) == length:
                    answer += 1
            result.append(answer)
    # print(result)
    return result


words = ["frodo", "front", "frost", "frozen", "frame", "kakao"]
queries = ["fro??", "????o", "fr???", "fro???", "pro?"]
solution(words, queries)



