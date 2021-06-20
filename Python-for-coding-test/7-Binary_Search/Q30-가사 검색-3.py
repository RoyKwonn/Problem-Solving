import sys

sys.setrecursionlimit(100001)

def solution(words, queries):
    answer = []

    rev_words, counted = [], []  # 조건 b, c를 위한 두 변수
    for w in words:
        rev_words.append(w[::-1])
        counted.append(len(w))

    trie = make_trie({}, words)  # 조건 a 의 trie
    rev_trie = make_trie({}, rev_words)  # 조건 b 의 rev_trie

    for query in queries:  # 3가지 조건으로 나누어서,
        if query[0] == '?' and query[-1] == '?':
            answer.append(counted.count(len(query)))
        elif query[0] == '?':
            answer.append(search_trie(rev_trie, query[::-1], len(query)))
        elif query[-1] == '?':
            answer.append(search_trie(trie, query, len(query)))

    return answer


def make_trie(trie, words):
    for word in words:
        cur = trie
        l = len(word)
        for w in word:
            if w in cur:
                cur = cur[w]
                cur['!'].append(l)
            else:
                cur[w] = {}
                cur = cur[w]
                cur['!'] = [l]
    return trie


def search_trie(trie, query, length):
    count = 0
    if query[0] == '?':
        return trie['!'].count(length)
    elif query[0] in trie:
        count += search_trie(trie[query[0]], query[1:], length)

    return count


words = ["frodo", "front", "frost", "frozen", "frame", "kakao"]
queries = ["fro??", "????o", "fr???", "fro???", "pro?"]
solution(words, queries)

