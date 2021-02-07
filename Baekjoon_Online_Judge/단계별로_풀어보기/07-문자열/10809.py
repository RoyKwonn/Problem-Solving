s = str(input())
li = []

for i in range(ord('a'),ord('z')+1): # 아스키코드 값으로 범위지정
  a = s.find(chr(i)) # 각각의 알파벳에 대한 내용이 있는지 확인
  li.append(a) # 못찾으면 -1 찾으면 해당하는 인덱스를 표시

for i in li:
  print(i, end=" ")