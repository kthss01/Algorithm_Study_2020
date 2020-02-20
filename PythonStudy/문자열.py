# 문자열 인덱싱
a = "07:05:45PM"
b = a[-2] + a[-1] # PM

# 문자열 슬라이싱
c = a[-2:] # PM
d = a[:-2] # 07:05:45
e = int(a[:2]) # hour

# 문자열 포맷
"I have %s apples" % 3
'%2d' % e
# 포매팅 연산자 %d와 %를 같이 쓸 때는 %%를 씀
"Error is %d%%." % 98
# format 함수를 사용한 포매팅
"I eat {0} apples".format(3)
number = 10
day = "three"
"I ate {0} apples. so I was sick for {1} days.".format(number, day)