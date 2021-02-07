dial = ['ABC', 'DEF', 'GHI', 'JKL', 'MNO', 'PQRS', 'TUV', 'WXYZ']
a = input()     # 입력값 넣기
ret = 0         # 결과값 만들기
for j in range(len(a)): # 글자 총길이
    for i in dial:      # 입력한 글자가, 다이얼에 있다면?
        if a[j] in i:
            ret += dial.index(i)+3 # 다이얼이 늘어날때마다
print(ret)