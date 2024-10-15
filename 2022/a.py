t = int(input())
for i in range(t):
    family_count, rows = map(int, input().split())
    family_members_list = map(int, input().split())

    happy = 0
    odd_ones = 0

    for family_members in family_members_list:
        rows_used = family_members // 2
        odd_ones += family_members % 2

        happy += rows_used * 2

        rows -= rows_used
    
    if rows >= odd_ones:
        happy += odd_ones
    else:
        happy += (rows * 2) - odd_ones
    print(happy)



