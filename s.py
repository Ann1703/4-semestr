import random
import time
import sys


sys.setrecursionlimit(30000)

class OperationCounter:
    def __init__(self):
        self.comparisons = 0
        self.swaps = 0
        self.assignments = 0
    
    def reset(self):
        self.comparisons = 0
        self.swaps = 0
        self.assignments = 0
    
    def total_operations(self):
        return self.comparisons + self.swaps + self.assignments


counter = OperationCounter()


def bubble_sort(arr):
    counter.reset()
    n = len(arr)
    
    for i in range(n):
        for j in range(0, n - i - 1):
            counter.comparisons += 1
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                counter.swaps += 1
                counter.assignments += 2
    
    return arr

def insertion_sort(arr):
    counter.reset()
    
    for i in range(1, len(arr)):
        key = arr[i]
        counter.assignments += 1
        
        
        low, high = 0, i - 1
        while low <= high:
            counter.comparisons += 1
            mid = (low + high) // 2
            if key < arr[mid]:
                high = mid - 1
            else:
                low = mid + 1
        
       
        for j in range(i - 1, low - 1, -1):
            arr[j + 1] = arr[j]
            counter.assignments += 1
        
        arr[low] = key
        counter.assignments += 1
    
    return arr



def quick_sort_iterative(arr):
    counter.reset()
    if len(arr) <= 1:
        return arr
    
    stack = [(0, len(arr) - 1)]
    
    while stack:
        low, high = stack.pop()
        
        if low < high:
            counter.comparisons += 1
            pi = partition_hoare(arr, low, high)
            
            
            stack.append((low, pi))      
            stack.append((pi + 1, high)) 

def partition_hoare(arr, low, high):
     
    pivot = arr[(low + high) // 2]
    i = low - 1
    j = high + 1
    
    while True:
        
        i += 1
        while arr[i] < pivot:
            counter.comparisons += 1
            i += 1
        
        
        j -= 1
        while arr[j] > pivot:
            counter.comparisons += 1
            j -= 1
        
        
        if i >= j:
            return j
        
       
        arr[i], arr[j] = arr[j], arr[i]

def main():
    
    print("Генерация массива из 10000 случайных чисел...")
    original_array = [random.randint(1, 100000) for i in range(10000)]
    
    print("\nСравнение алгоритмов сортировки")

    algorithms = [
        ("Пузырьковая", bubble_sort),
        ("Вставками", insertion_sort),
        ("Метод Хоара", quick_sort_iterative)
    ]
    
    results = []
    
    for name, algo in algorithms:
        test_arr = original_array.copy()
        start_time = time.time()
        algo(test_arr)
        end_time = time.time()
        
        results.append((
            name,
            end_time - start_time,
            counter.total_operations()
        ))
   
    print("\nРзультат:")
    print(f"{'Алгоритм':<15} {'Время (с)':<12} {'Операций':<15}")
    for name, time_val, total in results:
        print(f"{name:<15} {time_val:<12.4f} {total:<15}")

if __name__ == "__main__":
    main()
