def check(x):
    x = str(x)
    if x == x[::-1]:
        return "true"
    else:
        return "false"
    
print(check(10))