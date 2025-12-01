import random

def insert_sort(arr):
    
    if not arr:
        raise ValueError("empty array")
    
    comparision = 0
    temp = []
    temp.append(arr[0])
    
    for i in range(1, len(arr)):
        inserted = False
        for j in range(len(temp)):
            comparision += 1
            if arr[i] < temp[j]:
                temp.insert(j, arr[i])
                inserted = True
                break
        if not inserted:
            temp.append(arr[i])
    
    print(f"Количество операций сравнения (вставка): {comparision}")
    return temp

def quick_sort(arr):
    
    if len(arr) <= 1:
        return arr

    pivot = arr[len(arr) // 2]
    
    left, middle, right = [], [], []
    
    for x in arr:
        if x < pivot:
            left.append(x)
        elif x == pivot:
            middle.append(x)
        else:
            right.append(x)
    
    return quick_sort(left) + middle + quick_sort(right)

def quick_sort_with_count(arr, operations_counter=None):
    
    if operations_counter is None:
        operations_counter = [0]
    
    if len(arr) <= 1:
        return arr, operations_counter[0]

    pivot = arr[len(arr) // 2]
    operations_counter[0] += 1  
    
    left, middle, right = [], [], []
    
    for x in arr:
        operations_counter[0] += 1  
        if x < pivot:
            left.append(x)
        elif x == pivot:
            middle.append(x)
        else:
            right.append(x)
        operations_counter[0] += 1      
    
    left_sorted, _ = quick_sort_with_count(left, operations_counter)
    right_sorted, _ = quick_sort_with_count(right, operations_counter)
    
    
    return left_sorted + middle + right_sorted, operations_counter[0]

def main():
    
    arr = []
    for i in range(0, 10000):
        arr.append(random.randint(1, 100000))
    
    print(f"Размер массива: {len(arr)} элементов")
    print(f"Диапазон значений: от {min(arr)} до {max(arr)}")
    
    
    print("\nСортировка вставкой")
    sorted_insert = insert_sort(arr.copy())
    print(f"Проверка сортировки: {sorted_insert == sorted(arr)}")
    
    
    print("\nБыстрая сортировка (Хоара)")
    sorted_quick = quick_sort(arr.copy())
    print(f"Проверка сортировки: {sorted_quick == sorted(arr)}")
    
    
    print("\nБыстрая сортировка с подсчетом операций")
    sorted_quick_count, operations = quick_sort_with_count(arr.copy())
    print(f"Количество операций (быстрая): {operations}")
    print(f"Проверка сортировки: {sorted_quick_count == sorted(arr)}")
    
    
    print("\nСравнение эффективности")
    expected_operations = len(arr) * (len(arr).bit_length())  
    print(f"Ожидаемое количество операций (теория): ~{expected_operations}")
    print(f"Фактическое количество операций: {operations}")
    print(f"Отношение факт/теория: {operations/expected_operations:.2f}")

if __name__ == "__main__":
    main()
