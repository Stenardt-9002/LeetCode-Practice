def fuc(s):
    cnt = 0 
    while('01' in s):
        s = s.replace('01','10')
        cnt+=1

    return cnt 