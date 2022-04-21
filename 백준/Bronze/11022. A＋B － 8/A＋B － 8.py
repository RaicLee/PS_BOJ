x = int(input())
for i in range(1,x+1):
    a,b = map(int,input().split())
    print("Case #{}: {} + {} = {}".format(i,a,b,a+b))
    