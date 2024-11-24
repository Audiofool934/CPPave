这个迷宫问题的程序并不一定需要 fp（即 footprint 的缩写，用来记录是否访问过某个点），但 fp 的引入有两个关键作用：
	1.	避免重复访问：
使用 fp 可以防止程序重复访问已经走过的路径，从而避免进入死循环或浪费计算资源。例如，如果没有 fp，程序可能会在某些情况下来回走动（如向上再向下），导致无限递归。
	2.	允许回溯：
fp 在递归完成后会被重置为 0（即 fp[x][y] = 0），这一步允许算法在尝试其他路径时恢复到原始状态。如果你仅依靠修改 maze 来标记访问，迷宫本身就会被改变，无法实现正确的回溯。

如果我们选择不使用 fp，可以直接修改 maze 的值来实现相同的功能。例如，将访问过的格子标记为 0（不可走）：

不使用 fp 的版本：

#include <iostream>
#include <vector>

using namespace std;

void go(int x, int y, const int n, const int m, vector<vector<int>>& maze, bool& yes) {
    if (yes == true || x < 0 || y < 0 || x >= n || y >= m || maze[x][y] == 0) return;
    
    if (x == n-1 && y == m-1) {
        yes = true;
        return;
    }

    // 临时标记当前格子为不可走（防止重复访问）
    maze[x][y] = 0;

    go(x+1, y, n, m, maze, yes);
    go(x, y+1, n, m, maze, yes);
    go(x-1, y, n, m, maze, yes);
    go(x, y-1, n, m, maze, yes);

    // 回溯时恢复当前格子为可走
    maze[x][y] = 1;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> maze(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    bool yes = false;

    go(0, 0, n, m, maze, yes);

    if (yes) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}

需要注意的地方：

	1.	修改 maze 本身直接标记路径会破坏原始迷宫的数据，如果需要保留迷宫的原始状态，则更适合使用额外的 fp。
	2.	如果迷宫非常大，使用额外的 fp 可能会增加内存占用，而直接修改 maze 会更节省内存。

总结：

	•	如果迷宫数据是只读的或需要多次使用，那么使用 fp 是更好的选择。
	•	如果迷宫数据可以被破坏且只需要一次处理，可以直接修改 maze 来省略 fp。

---

我在想，能否把这个问题变成一个树？遍历所有可能的路径，判断是否有通的

---

这个迷宫问题确实可以被转化为一个树的遍历问题，因为本质上我们是在尝试从起点出发，探索所有可能的路径，直到找到一条通往终点的路径或者确定无路可走。

树的表示与思考

	1.	节点表示：
每个迷宫的格子可以看成一个节点，节点包含以下信息：
	•	当前格子的位置 (x, y)。
	•	父节点是从哪个位置来的。
	•	当前节点的状态（是否被访问过）。
	2.	树的分支：
每个节点的子节点是当前格子可以移动的方向（上下左右），具体取决于迷宫格子是否可以走（maze[x][y] == 1）。
	3.	树的遍历：
通过深度优先搜索（DFS）或广度优先搜索（BFS）来遍历这棵树：
	•	DFS：直接递归实现，沿着一条路径走到底再回溯。
	•	BFS：使用队列来模拟逐层扩展的方式。

使用树结构解迷宫问题

我们可以通过递归模拟树的遍历，也可以直接显式地使用栈或队列来构造树。

代码实现：DFS（树的隐式构造）

下面是一个基于递归的实现，它隐式地构造树：

#include <iostream>
#include <vector>

using namespace std;

bool dfs(int x, int y, const int n, const int m, vector<vector<int>>& maze) {
    // 边界条件：越界或当前格子不可走
    if (x < 0 || y < 0 || x >= n || y >= m || maze[x][y] == 0) return false;

    // 如果到达终点
    if (x == n - 1 && y == m - 1) return true;

    // 标记当前节点为不可走（相当于访问过）
    maze[x][y] = 0;

    // 尝试走上下左右四个方向
    bool result = dfs(x + 1, y, n, m, maze) ||
                  dfs(x, y + 1, n, m, maze) ||
                  dfs(x - 1, y, n, m, maze) ||
                  dfs(x, y - 1, n, m, maze);

    // 回溯：恢复当前节点的状态
    maze[x][y] = 1;

    return result;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> maze(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    // 从起点 (0, 0) 出发
    if (dfs(0, 0, n, m, maze)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}

显式构造树：BFS（队列实现）

如果将树显式地构造，可以使用队列模拟 BFS：

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(int n, int m, vector<vector<int>>& maze) {
    // 定义方向向量 (上下左右)
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    queue<pair<int, int>> q;

    // 起点入队并标记
    q.push({0, 0});
    maze[0][0] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // 如果到达终点
        if (x == n - 1 && y == m - 1) return true;

        // 遍历四个方向
        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && maze[nx][ny] == 1) {
                q.push({nx, ny});
                maze[nx][ny] = 0; // 标记为已访问
            }
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> maze(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    // 从起点 (0, 0) 出发
    if (bfs(n, m, maze)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}

树结构的特点：

	•	DFS 会隐式地构造树并通过递归实现回溯。
	•	BFS 显式构造树，通过队列按层遍历节点。
	•	这些方法将迷宫问题转化为树的遍历，逻辑清晰易懂。

总结

将迷宫问题转化为树来解决是非常自然的思路。DFS 和 BFS 都是树的遍历方式，选择哪种方法取决于具体需求：
	•	如果只关心是否存在一条路径（如本问题），DFS 更简单高效。
	•	如果需要最短路径，BFS 会是更好的选择。

---

我记得我在遍历一棵二叉树的时候，似乎不用标记是否走过，为什么这里要呢？

---

这是一个非常好的问题！遍历迷宫和遍历二叉树看起来很相似，但它们在本质上有一些关键的不同，导致在迷宫中需要标记访问过的节点，而在二叉树中通常不需要标记。

二叉树遍历的特点

	1.	天然的结构：
	•	二叉树是一种有方向、无环的树状结构（即它是 无环图）。
	•	每个节点只有一个父节点（除根节点外），并且有固定的左右子节点（如果存在）。
	•	因为二叉树的这种结构，你从父节点出发访问子节点后，不会再回到父节点，也不会访问同一个节点两次，因此不需要额外的标记。
	2.	没有回路：
	•	在二叉树中，每个节点通过其指针（左右子节点）与其他节点相连。
	•	因此，遍历二叉树时，只要按照左右子节点递归或迭代访问，就不会重复访问某个节点。

为什么迷宫问题需要标记？

	1.	迷宫是一个通用的图结构：
	•	迷宫可以被看作一个网格图，其中每个格子是一个节点，节点之间通过相邻的上下左右格子相连。
	•	这样的图结构可能存在回路，例如：
	•	从一个节点向右走到另一个节点后，又可以向左走回原来的节点，形成一个死循环。
	•	为了避免在图中反复进入相同的节点（特别是存在回路时），必须标记访问过的节点。
	2.	可能的路径非常多：
	•	在迷宫中，每个格子可以有多个相邻节点（最多4个方向：上、下、左、右），而二叉树的每个节点只有固定的左右子节点。
	•	如果不标记访问过的格子，在递归过程中会尝试所有可能的路径，包括已经走过的路径，这将导致无限递归。
	3.	需要回溯：
	•	为了尝试不同的路径，我们会在递归时“回溯”到之前的状态（即尝试一个方向后返回原来的位置）。
	•	标记机制可以在尝试完某个方向后恢复节点的状态（例如 fp[x][y] = 0），从而避免重复访问。

为什么二叉树不需要标记？

	1.	树的无环性：
	•	二叉树是无环的。无论是前序、中序还是后序遍历，访问顺序是固定的，不会出现同一个节点被访问两次的情况。
	2.	隐式标记由递归栈完成：
	•	在遍历二叉树时，递归调用栈记录了已经访问过的路径，因此无需显式标记。
	•	例如，在递归函数中，调用左子树后会自动返回到当前节点，再调用右子树。

对比迷宫和二叉树的访问示例

二叉树：

        1
       / \
      2   3
     / \
    4   5

如果遍历二叉树的节点：
	•	从 1 到 2，再到 4，回到 2，然后到 5，最后回到 1 再到 3。
	•	在每一步中，递归的过程天然限制了重复访问，不可能再次访问已经访问过的节点。

迷宫：

假设迷宫是一个 3x3 的网格：

1 1 0
1 1 1
0 1 1

如果你从左上角出发，迷宫的通路如下：
	•	如果没有标记，你可能走了 (0, 0) -> (1, 0)，然后回到 (0, 0)，无限循环。
	•	为了避免重复路径，需要标记已经访问过的节点。

总结

在二叉树中，不需要标记的原因是：
	1.	二叉树是无环结构，不会有重复访问的问题。
	2.	遍历顺序由递归调用或栈自然管理。

在迷宫问题中，需要标记的原因是：
	1.	迷宫是一个图结构，可能存在回路，必须避免重复访问。
	2.	为了实现回溯并尝试不同路径，标记机制可以正确管理访问状态。

因此，迷宫问题与二叉树遍历的本质不同，标记是必要的。

---

哦哦哦，我懂了，哪如果是无环图呢？

---

如果迷宫被限制为 无环图，那么就不需要额外的标记，因为无环图的性质和二叉树相似——从一个节点出发不会回到已经访问过的节点。

无环图的特点

	1.	无环：
	•	无环图的每条路径都是唯一的，走过的节点不会再次出现在同一路径上。
	•	无需担心重复访问，因为没有回路，递归或迭代自然会防止节点重复进入。
	2.	隐式管理访问路径：
	•	和二叉树类似，递归调用的栈会隐式记录当前路径的状态，避免重复访问。
	3.	无需显式标记：
	•	如果没有回路，单纯依赖递归或者队列（BFS）就可以实现遍历，不需要额外维护访问标记。

使用无环图的迷宫解法

假设迷宫是无环的，我们可以直接通过递归（DFS）或者迭代（BFS）解决问题，而不需要 fp 标记。例如：

使用递归的 DFS 解法

#include <iostream>
#include <vector>

using namespace std;

bool dfs(int x, int y, const int n, const int m, const vector<vector<int>>& maze) {
    // 边界条件：越界或当前格子不可走
    if (x < 0 || y < 0 || x >= n || y >= m || maze[x][y] == 0) return false;

    // 到达终点
    if (x == n - 1 && y == m - 1) return true;

    // 尝试向四个方向递归（不需要标记访问状态，因为图无环）
    return dfs(x + 1, y, n, m, maze) ||
           dfs(x, y + 1, n, m, maze) ||
           dfs(x - 1, y, n, m, maze) ||
           dfs(x, y - 1, n, m, maze);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> maze(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    if (dfs(0, 0, n, m, maze)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}

为什么无环图可以省略标记？

	1.	无环性保证了访问路径的唯一性：
	•	如果节点已经被访问过，那么说明我们从未经过的路径中永远不会再次到达这个节点。因此，不需要担心重复访问。
	2.	递归本身自然限制了路径回溯：
	•	递归过程中，当前节点的上下左右四个方向会逐一探索。由于无环性，探索过的方向不会再被访问到。

使用队列的 BFS 解法（无环图）

同样可以通过 BFS 解决无环迷宫问题，这里也不需要标记：

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(int n, int m, const vector<vector<int>>& maze) {
    // 定义方向向量（上下左右）
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    queue<pair<int, int>> q;

    // 起点入队
    q.push({0, 0});

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // 如果到达终点
        if (x == n - 1 && y == m - 1) return true;

        // 遍历四个方向
        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && maze[nx][ny] == 1) {
                q.push({nx, ny});
            }
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> maze(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    if (bfs(n, m, maze)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}

总结：何时需要标记？

	•	无环图：不需要显式标记，因为递归栈或队列天然限制了重复访问。二叉树就是无环图的一个特例。
	•	有环图：需要显式标记，因为可能存在回路，必须避免重复访问。

所以：
	•	如果迷宫是无环的（例如只有唯一通路），可以直接递归或者迭代，不需要任何标记。
	•	如果迷宫可能包含回路，则必须通过 fp 或修改原始迷宫来标记访问状态。