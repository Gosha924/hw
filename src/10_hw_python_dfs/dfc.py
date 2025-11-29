class Graph:
    def __init__(self):
        self.adjacency_list = {}

    def add_vertex(self, vertex):
        """Добавление вершины в граф"""
        if vertex not in self.adjacency_list:
            self.adjacency_list[vertex] = []

    def add_edge(self, vertex1, vertex2):
        """Добавление ребра между вершинами"""
        if vertex1 not in self.adjacency_list:
            self.add_vertex(vertex1)
        if vertex2 not in self.adjacency_list:
            self.add_vertex(vertex2)

        if vertex2 not in self.adjacency_list[vertex1]:
            self.adjacency_list[vertex1].append(vertex2)
        if vertex1 not in self.adjacency_list[vertex2]:
            self.adjacency_list[vertex2].append(vertex1)

    def dfs(self, start_vertex=None):
        if not self.adjacency_list:
            return []

        if start_vertex is None:
            start_vertex = next(iter(self.adjacency_list))
        visited = []
        stack = [start_vertex]

        while stack:
            vertex = stack.pop()
            if vertex not in visited:
                visited.append(vertex)
                for neighbor in reversed(self.adjacency_list[vertex]):
                    if neighbor not in visited:
                        stack.append(neighbor)
        return visited

    def __iter__(self):
        self._dfs_iterator = iter(self.dfs())
        return self

    def __next__(self):
        return next(self._dfs_iterator)


g = Graph()
g.add_edge('A', 'B')
g.add_edge('A', 'C')
g.add_edge('B', 'D')
g.add_edge('B', 'E')
g.add_edge('C', 'F')
g.add_edge('E', 'F')
g.add_edge('E', 'Z')
g.add_edge('Z', 'W')

for elem in g:
    print(elem)
print("DFS  начиная с 'A':", g.dfs('A'))
print("DFS начиная с 'C':", g.dfs('C'))
