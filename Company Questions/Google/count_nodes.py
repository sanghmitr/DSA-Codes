import sys
import copy

# rlrliy
# rrrlihipqhl
# ryplihypp
# lytli

w = "ba"
x = "bc"
y = "bd"
z = "ac"

m=[[0 for _ in range(26)] for _ in range(4)]

for i in range(len(w)):
    m[0][ord(w[i])-ord('a')]+=1
for i in range(len(x)):
    m[1][ord(x[i])-ord('a')]+=1
for i in range(len(y)):
    m[2][ord(y[i])-ord('a')]+=1
for i in range(len(z)):
    m[3][ord(z[i])-ord('a')]+=1

def solve(p):
    global m 
    ans=0
    mod=10**9+7
    curr=-1
    valid=0
    for i in range(4):
        if p[i]:
            curr=i
            valid+=1
    if valid==1:
        #print(p)
        for i in range(26):
            ans+=m[curr][i]
        return ans
            
    for i in range(26):
        count=mod
        for j in range(4):
            if p[j]:
                count=min(m[j][i],count)
                
        if count!=mod and count!=0:
            ans+=count
            for j in range(4):
                if p[j]:
                    m[j][i]-=count
          
    p1=[0,0,0,0]
    p2=[0,0,0,0]
    
    left=-1
    for i in range(4):
        if p[i]:
            p1[i]=1
            left=i
            break
            
          
    for i in range(4):
        if i!=left and p[i]:
            flag=1
            for c in range(26):
                if m[i][c] and m[left][c]:
                    ##print(c,i)
                    p1[i]=1
                    flag=0
                    break
                    
            if flag:
                p2[i]=1
                
    if p==p1:
        mask=0
        
        for i in range(4):
            if p[i]:
                mask+=1<<i
                
                
        best=sys.maxsize
        s=mask
        mtemp=copy.deepcopy(m) 
        
        while s>0:
            if s!=mask:
                p1=[0,0,0,0]
                p2=[0,0,0,0]
                
                other=mask^s
                for i in range(4):
                    if (s>>i & 1)==1:
                        p1[i]=1
                    elif (other>>i & 1)==1:
                        p2[i]=1
                
                     
                m=copy.deepcopy(mtemp)
                temp=solve(p1)+solve(p2)
                best=min(temp,best)
                
            
            s=(s-1)&mask
        
        ans+=best
        return ans
          
    ans+=solve(p1)+solve(p2)
    return ans


print(solve([1,1,1,1]))  