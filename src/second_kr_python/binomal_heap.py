class BinomialTree:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.children = []
        self.order = 0
 
    def add_at_end(self, elem):
        self.children.append(elem)
        self.order = self.order + 1
 
 
class BinomialHeap:
    def __init__(self):
        self.trees = []
 
    def get_min(self):
        if self.trees == []:
            return None
        least = self.trees[0].key
        data = self.trees[0].value
        for tree in self.trees:
            if tree.key < least:
                least = tree.key
                data = tree.value
        return (least, data)
 
    def combine_roots(self, h):
        self.trees.extend(h.trees)
        self.trees.sort(key=lambda tree: tree.order)
 
    def merge(self, h):
        self.combine_roots(h)
        if self.trees == []:
            return
        i = 0
        while i < len(self.trees) - 1:
            current = self.trees[i]
            after = self.trees[i + 1]
            if current.order == after.order:
                if (i + 1 < len(self.trees) - 1) and (self.trees[i + 2].order == after.order):
                    after2 = self.trees[i + 2]
                    if after.key < after2.key:
                        after.add_at_end(after2)
                        del self.trees[i + 2]
                    else:
                        after2.add_at_end(after)
                        del self.trees[i + 1]
                else:
                    if current.key < after.key:
                        current.add_at_end(after)
                        del self.trees[i + 1]
                    else:
                        after.add_at_end(current)
                        del self.trees[i]
            i = i + 1
        
    def extract_min(self):
        if self.trees == []:
            return None
        smallest_node = self.trees[0]
        for tree in self.trees:
            if tree.key < smallest_node.key:
                smallest_node = tree
        self.trees.remove(smallest_node)
        h = BinomialHeap()
        h.trees = smallest_node.children
        self.merge(h)
        return (smallest_node.key, smallest_node.value)

    def insert(self, key, value):
        heap = BinomialHeap()
        heap.trees.append(BinomialTree(key, value))
        self.merge(heap)
