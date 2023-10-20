class My_Priory_Queue:
    def __init__(self):
        self.queue = list()
        
    def is_empty(self):
        if len(self.queue) != 0:
            return False
        return True
    
    def insert(self, n):
        if self.is_empty():
            self.queue.append(n)
        else:
            if self.queue[-1] < n:
                self.queue.append(n)
            else:
                for i in range(len(self.queue)):
                    if self.queue[i] > n:
                        self.queue = self.queue[:i] + [n] + self.queue[i:]
                        break
    
    def delete_max(self):
        if not self.is_empty():
            self.queue = self.queue[:-1]
    
    def delete_min(self):
        if not self.is_empty():
            self.queue = self.queue[1:]
    
    def get_max(self):
        if not self.is_empty():
            return self.queue[-1]
    
    def get_min(self):
        if not self.is_empty():
            return self.queue[0]

def solution(operations):
    pq = My_Priory_Queue()
    
    for op in operations:
        if op == "D 1":
            pq.delete_max()
            continue
        elif op == "D -1":
            pq.delete_min()
            continue
        
        splited_op = op.split()
        if splited_op[0] == "I":
            pq.insert(int(splited_op[1]))
    
    if pq.is_empty():
        return [0,0]
    return [pq.get_max(), pq.get_min()]

# lines for test
operations0 = ["I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"]
operations1 = ["I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"]
print(solution(operations0))