def reverse_and_add(n, iterations):
    for _ in range(iterations):
        n = n + int(str(n)[::-1])
    return n

# Simulate 44 iterations for 196
for i in range(46):
    result = reverse_and_add(196, i)
    print(f"{i}: {result}")
# result = reverse_and_add(196, 44)
# result