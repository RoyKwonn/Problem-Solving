hour, minute = input().split()

hour = int(hour)
minute = int(minute)

if minute < 45:
    hour = (hour + 24 - 1) % 24
    minute = (minute + 60 - 45) % 60
else:
    minute -= 45

print("%d %d" %(hour, minute) )