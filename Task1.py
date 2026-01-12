import random
INF = float('inf')

try:
    n = int(input("\nВведите число узлов (n): "))
    V = [[0]*n for _ in range(n)]
   
    for i in range(n):
        for j in range(n):
            if i == j:
                V[i][j] = 0
            elif random.random() < 0.3:
                V[i][j] = INF
            else:
                V[i][j] = random.randint(1, 10)
    print("\nМатрица V[i][j]:")
    for i in range(n):
        row = ""
        for j in range(n):
            if V[i][j] == INF:
                row += " ∞ "
            else:
                row += f"{V[i][j]:2d} "
        print(row)
    dist = [row[:] for row in V]
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][k] != INF and dist[k][j] != INF:
                    new_dist = dist[i][k] + dist[k][j]
                    if new_dist < dist[i][j]:
                        dist[i][j] = new_dist
    start = int(input(f"Начальный узел (0-{n-1}): "))
    end = int(input(f"Конечный узел (0-{n-1}): "))
    result = dist[start][end]
    print(f"\nРезультат: расстояние от {start} до {end} = ", end="")
    if result == INF:
        print("∞ (пути не существует)")
    else:
        print(result)
except ValueError:
    print("Ошибка! Нужно вводить числа.")
except IndexError:
    print("Ошибка! Неправильный номер узла.")
