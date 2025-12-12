from binomal_heap import BinomialHeap

def test1():
    test_heap = BinomialHeap()
    
    test_heap.insert(1, 'one')
    test_heap.insert(2, 'two')
    test_heap.insert(3, 'three')

    results = []
    need_results = ['one', 'two', 'three']

    results.append(test_heap.extract_min()[1])
    results.append(test_heap.extract_min()[1])
    results.append(test_heap.extract_min()[1])
    if results == need_results:
        print('test1 passed')
    else:
        print('test1 FAILED')

def test2():
    test_heap = BinomialHeap()
    
    test_heap.insert(-1, 'one')
    test_heap.insert(-2, 'two')
    test_heap.insert(-3, 'three')

    results = []
    need_results = ['three', 'two', 'one']

    results.append(test_heap.extract_min()[1])
    results.append(test_heap.extract_min()[1])
    results.append(test_heap.extract_min()[1])
    if results == need_results:
        print('test2 passed')
    else:
        print('test2 FAILED')

test1()
test2()