# 재귀적으로 구현하여 해결할 수 있다.
# 구현을 위한 알고리즘 자체는 문제에 그대로 제시되어 있다.
# 엄밀히 말하면 이 문제는 DFS 문제는 아니다.


# "균형잡힌 괄호 문자열"의 인덱스 반환
def balanced_index(p):
    count = 0 # 왼쪽 괄호의 개수
    for i in range(len(p)):
        if p[i] == '(':
            count += 1
        else:
            count -= 1
        if count == 0:
            return i

# "올바른 괄호 문자열"인지 판단
def check_proper(p):
    count = 0 # 왼쪽 괄호의 개수
    for i in p:
        if i == '(':
            count += 1
        else:
            if count == 0: # 쌍이 맞지 않는 경우에 False 반환
                return False
            count -= 1
    return True # 쌍이 맞는 경우에 True 반환

def solution(p):
    answer = ''

    p = p.strip()  # 속도를 올리기 위해 사용한다.
    if p == '':   # 내가 진행하지 않았던 내용
        return answer


    index = balanced_index(p)
    u = p[:index + 1]
    v = p[index + 1:]

    # "올바른 괄호 문자열"이면, v에 대해 함수를 수행한 결과를 붙여 반환
    if check_proper(u):
        answer = u + solution(v)
    # "올바른 괄호 문자열"이 아니라면 아래의 과정을 수행
    else:
        answer = '('
        answer += solution(v)
        answer += ')'
        u = list(u[1:-1]) # 첫 번째와 마지막 문자를 제거
        for i in range(len(u)):
            if u[i] == '(':
                u[i] = ')'
            else:
                u[i] = '('
        answer += "".join(u)
    return answer

