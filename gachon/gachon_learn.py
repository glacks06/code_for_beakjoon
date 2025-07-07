


sub = int(input())
a = input()
# c = [] # 불필요 (왜 불필요한지 잘 모르겠으면 나한테 다시 물어보셈)
c = list(map(int,a.split(' ')))
maxA = max(c)
b=0
for i in c:
    a1 = int(i)/int(maxA) *100
    b += a1

print(b/sub)    

# 참고
# 보통 무언가를 합산하는 변수 이름은 sum이라고 함.
# 그래서 이 코드에서 변수 b는 통상적으로 sum이라고 자주 씀. (물론 강제 아님. 편한대로 하되 다른사람들이랑 같이 프로젝트 할 때는 이런거 지키면 편함.)
