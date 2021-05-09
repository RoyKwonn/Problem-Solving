# data = input()
#
# count0 = 0
# count1 = 0
#
# if(data[0] == '0'):
#     count0 += 1
# else:
#     count1 += 1
#
# for i in range(len(data) - 1):
#     if(data[i] != data[i + 1]):
#         if(data[i + 1] == '1'):
#             count0 += 1
#         else:
#             count1 += 1
#
# print(min(count0, count1))

# -----------------------------------------------------

# data = list(map(lambda x: bool(int(x)), input()))
# count = 0
#
# while data:
#     if data[0] != data[-1]:         # 시작과 끝이 다르면 잘라서 같게 만듬
#         start = 0
#         while data[start] == data[start + 1]:
#             start += 1
#         data = data[start+1:]
#         count += 1
#     else:
#         start, end = 0, len(data) - 1
#         while start < end and data[start] == data[start + 1]:
#             start += 1
#         if start == end:
#             break
#         while data[end] == data[end-1]:
#             end -= 1
#         data = data[start+1:end]
#
# print(count)

str = input()
count = 0
for i in range(len(str) - 1):
    if str[i] != str[i+1]:
        count += 1

print((count + 1) // 2)