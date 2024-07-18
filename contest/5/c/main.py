t = int(input())
for i in range(0, t):
    time = input()
    hour = time[0:2]
    minut = time[3:5]
    hour = int(hour)
    caps = ""
    if hour == 0:
        hour = 12
        caps = "AM"
    elif hour >= 1 and hour <= 11:
        caps = "AM"
    elif hour == 12:
        caps = "PM"
    else:
        hour = hour - 12
        caps = "PM"

    print(f"{hour:02d}:{minut} {caps}")
