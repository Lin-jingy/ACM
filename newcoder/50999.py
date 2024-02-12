a=input()
a=a.replace("/","//")
a=a.replace("^","**")
k=0
for i in a:
    if i=='(':k+=1
    elif i==')':k-=1
if k>0:a+=')'*k
else :a='('*(-k)+a
print(eval(a))