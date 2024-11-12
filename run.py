def reverse_and_add(n, iterations):
    for _ in range(iterations):
        n = n + int(str(n)[::-1])
    return n

for i in range(46):
    result = reverse_and_add(196, i)
    print(f"{i}: {result}")
    
