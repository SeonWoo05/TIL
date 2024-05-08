# # BJ 1010
# T = int(input())

# def comb(n,m):
#     a = n
#     b = m
#     for i in range(1,n):
#         a *= n - i
#     for i in range(1,n):
#         b *= m - i
#     return b / a

# for i in range(T):
#     n,m = map(int, input().split())
#     print(int(comb(n,m)))


# # BJ 1085
# x,y,w,h = map(int, input().split())
# A = min(x,y,w-x,h-y)
# print(A)
