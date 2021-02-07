a = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']
b = input()
for i in a:
    b = b.replace(i, '*') # 크로아티아 알패벳관련 문자를 하나로 바꾸어서 저장한다.
print(len(b)) # 변환된 글자의 갯수만 표시