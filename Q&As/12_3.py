def max_treasures(n, m, grid):
    # Initialize the dp array with negative infinity
    dp = [[[-float('inf')] * 3 for _ in range(m)] for _ in range(n)]
    
    # Starting point
    for d in range(3):
        dp[0][0][d] = grid[0][0]
    
    # Fill the dp array
    for i in range(n):
        for j in range(m):
            if i > 0:
                dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][0] + grid[i][j], dp[i-1][j][1] + grid[i][j], dp[i-1][j][2] + grid[i][j])
            if j > 0:
                dp[i][j][1] = max(dp[i][j][1], dp[i][j-1][0] + grid[i][j], dp[i][j-1][1] + grid[i][j])
            if j < m - 1:
                dp[i][j][2] = max(dp[i][j][2], dp[i][j+1][0] + grid[i][j], dp[i][j+1][2] + grid[i][j])
    
    # The result is the maximum value at the bottom-right corner considering all directions
    return max(dp[n-1][m-1])

# Example usage
n = 3
m = 4
grid = [
    [1, 3, 4, -6],
    [2, 3, -4, 8],
    [2, -5, 1, 0]
]

print(max_treasures(n, m, grid))  # Output: 12