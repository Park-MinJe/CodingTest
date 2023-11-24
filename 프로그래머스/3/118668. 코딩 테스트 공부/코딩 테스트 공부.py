from heapq import heappop, heappush

class Metadata:
    def __init__(self, req, rwd):
        self.req = req
        self.rwd = rwd
    def to_string(self):
        return "[req:{0}, rwd:{1}]".format(self.req, self.rwd)

class Problem:
    def __init__(self, problem):
        self.alp = Metadata(problem[0], problem[2])
        self.cop = Metadata(problem[1], problem[3])
        self.cost = problem[4]
    def possible_to_solve(self, p_alp, p_cop):
        return p_alp >= self.alp.req and p_cop >= self.cop.req
    def to_string(self):
        return "[alp:{0}, cop:{1}, cost:{2}]".format(self.alp.to_string(), self.cop.to_string(), self.cost)

def get_points_need_to_earn(max_alp_req, max_cop_req, alp, cop):
    return max_alp_req - alp if max_alp_req > alp else 0, max_cop_req - cop if max_cop_req > cop else 0

def solution(alp, cop, problems):
    obj_probs_list = []
    max_alp_req = -1
    max_cop_req = -1
    for problem in problems:
        obj_probs_list.append(Problem(problem))
        max_alp_req = max(max_alp_req, problem[0])
        max_cop_req = max(max_cop_req, problem[1])
    
    target_alp = min(alp, max_alp_req)
    target_cop = min(cop, max_cop_req)
    dp = [[float('inf')]*(max_cop_req + 1) for _ in range(max_alp_req + 1)]
    dp[target_alp][target_cop] = 0
    
    for i in range(target_alp, max_alp_req + 1):
        for j in range(target_cop, max_cop_req + 1):
            if i + 1 <= max_alp_req:
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1)
            if j + 1 <= max_cop_req:
                dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1)
            
            for obj_prob in obj_probs_list:
                if i >= obj_prob.alp.req and j >= obj_prob.cop.req:
                    next_alp, next_cop = min(max_alp_req, i + obj_prob.alp.rwd), min(max_cop_req, j + obj_prob.cop.rwd)
                    dp[next_alp][next_cop] = min(dp[next_alp][next_cop], dp[i][j] + obj_prob.cost)
    return dp[-1][-1]