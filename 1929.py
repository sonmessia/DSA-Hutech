from collections import defaultdict, deque

graph = defaultdict(list)
n = int(input().strip())
for i in range(n-1):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
def bfs(graph: dict, start: int) -> int:
    visited = [False] * (n+1)
    queue = deque([(start, 0)])
    visited[start] = True
    arr = []
    while queue:
        node, dist = queue.popleft()
        arr.append(dist)
        for neighbor in graph[node]:
            if not visited[neighbor]:
                visited[neighbor] = True
                queue.append((neighbor, (dist+1) % 2))
    sum1 = sum([1 for i in arr if i == 1])
    sum2 = sum([1 for i in arr if i == 0])
    return (sum1 - 1)*2 + (sum2 - 1)*2
degree = [0] * (n+1)
for i in range(1, n+1):
    degree[i] = len(graph[i])
    
for i in range(1, n+1):
    if degree[i] == 1:
        print(bfs(graph, i))
        break