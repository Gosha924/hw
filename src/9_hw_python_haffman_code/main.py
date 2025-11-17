import heapq


def encode(msg: str) -> tuple[str, dict[str, str]]:
    char_count = {}
    for char in msg:
        char_count[char] = msg.count(char)
    heap = []
    for char, count in char_count.items():
        heapq.heappush(heap, (count, [char]))
    # Построение дерева Хаффмана
    while len(heap) > 1:
        count1, chars1 = heapq.heappop(heap)
        count2, chars2 = heapq.heappop(heap)
        heapq.heappush(heap, (count1 + count2, chars1 + chars2))
    # Построение таблицы кодов
    codes = {}
    if heap:
        root_chars = heap[0][1]

        def assign_codes(chars, code):
            if len(chars) == 1:
                codes[chars[0]] = code
                return

            mid = len(chars) // 2
            left_chars = chars[:mid]
            right_chars = chars[mid:]
            assign_codes(left_chars, code + '0')
            assign_codes(right_chars, code + '1')
        assign_codes(root_chars, '')
    encoded_bits = ''.join(codes[char] for char in msg)
    return encoded_bits, codes


def decode(encoded: str, table: dict[str, str]) -> str:
    reverse_table = {}
    for char, code in table.items():
        reverse_table[code] = char
    decoded_chars = []
    current_code = ""
    for bit in encoded:
        current_code += bit
        if current_code in reverse_table:
            decoded_chars.append(reverse_table[current_code])
            current_code = ""
    return ''.join(decoded_chars)





# Пример использования
test_text = "sdnhgsrjhgsfxqqqq"
print(f"Исходный текст: {test_text}")
encoded, table = encode(test_text)
print(f"Закодированный текст: {encoded}")
print(f"Таблица кодирования: {table}")
decoded = decode(encoded, table)
print(f"Декодированный текст: {decoded}")
print(f"Совпадение: {test_text == decoded}")

