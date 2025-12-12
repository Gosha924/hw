from binomal_heap import BinomialHeap

binomal_heap = BinomialHeap()
print('Commands')
print('insert <key> <value>')
print('min get')
print('min extract')
print('quit')
 
while True:
    do = input('What would you like to do? ').split()
    operation = do[0]
    if operation == 'insert':
        key = int(do[1])
        data = do[2]
        binomal_heap.insert(key, data)
    elif operation == 'min':
        command = do[1]
        if command == 'get':
            print(f'Minimum value: {binomal_heap.get_min()[1]}')
        elif command == 'extract':
            print(f'Minimum value removed: {binomal_heap.extract_min()[1]}')
    elif operation == 'quit':
        break