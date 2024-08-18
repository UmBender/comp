def real_time_jump(val):
    minuts = val % 60
    hours = val // 60
    return (hours, minuts)


def is_palindrome(a, b):
    if len(a) == 1:
        a = " " + a
    if len(b) == 1:
        b = " " + b
    return a[::-1] == b


def next_moment(hour, minut, h_jump, m_jump):
    (hour, minut) = (int(hour), int(minut))
    minut += m_jump
    if minut > 59:
        hour += 1
        minut %= 60

    hour += h_jump
    if hour > 23:
        hour %= 24
    return (str(hour), str(minut))


def solution():
    iin = input()
    lista = iin.split(" ")
    clock = lista[0]
    jump = lista[1]
    begin_hour = clock[0:2]
    begin_minuts = clock[3:5]
    counter = 0
    if is_palindrome(begin_hour, begin_minuts):
        counter += 1
    (h_jump, m_jump) = real_time_jump(int(jump))
    (h, m) = next_moment(begin_hour, begin_minuts, h_jump, m_jump)
    while begin_hour != h or begin_minuts != m:
        if is_palindrome(begin_hour, begin_minuts):
            counter += 1
        (h, m) = next_moment(begin_hour, begin_minuts, h_jump, m_jump)
    print(counter)


t = int(input())
solution()
