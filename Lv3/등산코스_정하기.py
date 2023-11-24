import pprint as pp
from heapq import heappop, heappush

def dfs(n, adj, gates, summits, costs):
    pq = []
    visited = [100000001] * (n + 1)
    
    for gate in gates:
        heappush(pq, (0, gate))
        visited[gate] = 0
    
    while pq:
        #pp.pprint(pq)
        intensity, node = heappop(pq)
        
        if node in summits or intensity > visited[node]:
            continue
        
        for next_node in adj[node]:
            cost = costs[node][next_node]
            new_intensity = max(intensity, cost)
            if new_intensity < visited[next_node]:
                visited[next_node] = new_intensity
                heappush(pq, (new_intensity, next_node))
    
    #pp.pprint(visited)
    min_intensity = [0, 100000001]
    for summit in summits:
        #print(visited[summit])
        if visited[summit] < min_intensity[1]:
            min_intensity[0] = summit
            min_intensity[1] = visited[summit]
    
    min_intensity[0] += 1
    
    return min_intensity

'''
n       : 지점 수
paths   : 등산로 정보
gates   : 출입구 정보
summits : 산봉우리들의 번호
'''
def solution(n, paths, gates, summits):
    for i in range(len(gates)):
        gates[i] -= 1
    for i in range(len(summits)):
        summits[i] -= 1
    summits.sort()
    summits_set = set(summits)

    adj = [[] for _ in range(n)]
    costs = [[100000001] * n for _ in range(n)]
    
    # cost 초기화 및 인접 리스트 초기화
    for path in paths:
        heappush(adj[path[0] - 1], path[1] - 1)
        heappush(adj[path[1] - 1], path[0] - 1)

        costs[path[0] - 1][path[1] - 1] = path[2]
        costs[path[1] - 1][path[0] - 1] = path[2]
    
    #pp.pprint(adj)
    #pp.pprint(costs)
    
    return dfs(n, adj, gates, summits_set, costs)
    

_input = [
    [6, [[1, 2, 3], [2, 3, 5], [2, 4, 2], [2, 5, 4], [3, 4, 4], [4, 5, 3], [4, 6, 1], [5, 6, 1]],
     [1, 3], [5]],
    [7, [[1, 4, 4], [1, 6, 1], [1, 7, 3], [2, 5, 2], [3, 7, 4], [5, 6, 6]],
     [1], [2, 3, 4]],
    [7, [[1, 2, 5], [1, 4, 1], [2, 3, 1], [2, 6, 7], [4, 5, 1], [5, 6, 1], [6, 7, 1]],
     [3, 7], [1, 5]],
    [5, [[1, 3, 10], [1, 4, 20], [2, 3, 4], [2, 4, 6], [3, 5, 20], [4, 5, 6]],
     [1, 2], [5]]
]
for _in in _input:
    print("result:", solution(_in[0], _in[1], _in[2], _in[3]))
    print()