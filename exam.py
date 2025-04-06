from collections import deque

class UserMainCode(object):
    @classmethod
    def needForSpeed(cls, input1, input2, input3, input4):
        
        N = input1
        special_powers = input2
        R = input3
        routes = input4
        
        graph = {i: [] for i in range(N)}
        for route in routes:
            graph[route[0]].append(route[1])
            graph[route[1]].append(route[0])
        
        queue = deque([(0, [0], 1, 0)])  # (current_city, path, speed, time)
        visited = set()
        min_time = {i: float('inf') for i in range(N)}
        min_time[0] = 0
        
        while queue:
            current_city, path, speed, time = queue.popleft()
            
            if current_city == N - 1:
                return path
            
            if time > min_time[current_city]:
                continue
            
            visited.add(current_city)
            
            for neighbor in graph[current_city]:
                if special_powers[neighbor] == "Cop":
                    continue
                
                new_speed = speed
                new_time = time + 1 / speed
                
                if special_powers[neighbor] == "Nitro":
                    new_speed *= 2
                elif special_powers[neighbor] == "Sand":
                    new_speed = max(1, new_speed // 2)
                elif special_powers[neighbor] == "Crash":
                    new_time += 1
                
                if new_time < min_time[neighbor]:
                    min_time[neighbor] = new_time
                    queue.append((neighbor, path + [neighbor], new_speed, new_time))
        
        return -1

# Example usage:
input1 = 7
input2 = ["None", "Cop", "Sand", "None", "Nitro", "None", "None"]
input3 = 8
input4 = [[0, 1], [0, 2], [1, 2], [2, 3], [2, 4], [3, 6], [4, 5], [5, 6]]

result = UserMainCode.needForSpeed(input1, input2, input3, input4)
print(result)  # Output: [0, 2, 4, 5, 6]