def pow_log_n(x,n):
    """karmaşıklık = log n"""
    global s
    
    if(n==0):
        s=s+1
        return 1
    elif(n==1):
        s=s+1
        return x
    elif(n%2==0):
        s=s+1
        return pow(x*x,int(n/2))
    else:
        s=s+1
        return pow(x*x,int(n/2))*x

def pow_linear_log_n(x,n):
    result=1
    for i in range(n):
        result=reslut*x
    return result
