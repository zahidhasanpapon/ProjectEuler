# limit = 1000
# sum = 0
# for i in range(1, limit):
#     if i % 3 == 0 or i % 5 == 0:
#         sum += i
# print(sum)


def sumn(n, d):
    n //= d
    return d*n*(n+1)//2


L = int(input("Enter an upper bound? "))
a, b = 3, 5
s = sumn(L-1, a) + sumn(L-1, b) - sumn(L-1, a*b)
print(f"Sum of multiples of {a} or {b} below {L} = ", s)

