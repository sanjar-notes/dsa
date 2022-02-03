# cook your dish here
a, b, c = list(map(int, input().split()))

lis = list()

for i in range(a + b + c):

    lis.append(int(input()))

lis.sort()
import sys
sys.stdin = open("in.txt", "r")

rep = 0

outp = list()

i = 0

while i < len(lis):
    rep = 0
    while i < len(lis) - 1 and lis[i] == lis[i + 1]:
        i += 1
        rep += 1
    if rep != 0:
        outp.append(lis[i])
    i += 1
print(len(outp))
for i in outp:
    print(i)
