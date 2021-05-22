def answer(entrances, exits, path):
    residual = path[:]
    numBunnies = 0    
    prevNumBunnies = -1
    while prevNumBunnies != numBunnies:
        
        prevNumBunnies = numBunnies
    
        for j in entrances:
            visited = []
            path = []
            
            node = j        
            while 1:
                
                findUnvisited = False   
                
                visited.append(node)      
                
                maximum = 0
                index = 0
                
                for i in range(len(residual[node])):
                    if residual[node][i] > maximum and i not in visited:
                        maximum = residual[node][i]
                        index = i
                        findUnvisited = True
                
                if findUnvisited:
                    path.append(node)
                    node =index
                
                elif not path:
                    break   
                
                else:
                    node = path.pop()

                
                print(f"Node bdore if {node}")

                
                print("residual path before ")
                print(residual)

                if node in exits:
                    path.append(node)
                    minimum = 2000000
                    for j in range(len(path) - 1):
                        if residual[path[j]][path[j + 1]] < minimum:
                            minimum = residual[path[j]][path[j + 1]]
 
                    numBunnies += minimum
                    print("Path ")
                    print(path)

                    for j in range(len(path) - 2):
                        residual[path[j]][path[j + 1]] -= minimum
                        residual[path[j + 1]][path[j]] += minimum
                    residual[path[len(path) - 2]][path[len(path) - 1]] -= minimum
                    print("residual path after")
                    print(residual)
                    break

    return numBunnies

entrances = [0, 1]
exits = [4, 5]
path = [
  [0, 0, 4, 6, 0, 0],  # Room 0: Bunnies
  [0, 0, 5, 2, 0, 0],  # Room 1: Bunnies
  [0, 0, 0, 0, 4, 4],  # Room 2: Intermediate room
  [0, 0, 0, 0, 6, 6],  # Room 3: Intermediate room
  [0, 0, 0, 0, 0, 0],  # Room 4: Escape pods
  [0, 0, 0, 0, 0, 0],  # Room 5: Escape pods
]

print(answer(entrances,exits,path))