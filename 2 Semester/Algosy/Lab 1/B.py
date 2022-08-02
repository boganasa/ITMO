with open('aplusbb.in') as f_in:
        nums = f_in.read().split()
a, b = map(int, nums)
result = a + b**2
with open('aplusbb.out', 'w') as f_out:
    f_out.write(str(result))
