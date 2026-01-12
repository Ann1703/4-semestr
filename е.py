import random

def fermat(n):
    if n < 4:
        return n in [2, 3]
    
    for _ in range(5):
        a = random.randint(2, n-2)
        if pow(a, n-1, n) != 1:
            return False
    return True

def solovay_strassen(n):
    def jacobi(a, n):
        result = 1
        if a < 0:
            a = -a
            if n % 4 == 3:
                result = -result
        
        while a:
            while a % 2 == 0:
                a //= 2
                if n % 8 in [3, 5]:
                    result = -result
            a, n = n, a
            if a % 4 == 3 and n % 4 == 3:
                result = -result
            a %= n
        return result if n == 1 else 0
    
    for _ in range(5):
        a = random.randint(2, n-2)
        j = jacobi(a, n) % n
        x = pow(a, (n-1)//2, n)
        if x != j:
            return False
    return True

def miller_rabin(n):
    if n % 2 == 0:
        return n == 2
    
    d = n - 1
    s = 0
    while d % 2 == 0:
        d //= 2
        s += 1
    
    for _ in range(5):
        a = random.randint(2, n-2)
        x = pow(a, d, n)
        if x == 1 or x == n-1:
            continue
        
        for _ in range(s-1):
            x = pow(x, 2, n)
            if x == n-1:
                break
        else:
            return False
    return True

def main():
    print("1 - Ферма")
    print("2 - Соловей-Штрассен")
    print("3 - Миллер-Рабин")
    
    c = input("Выбор: ")
    n = int(input("Число: "))
    
    if c == '1':
        r = fermat(n)
    elif c == '2':
        r = solovay_strassen(n)
    elif c == '3':
        r = miller_rabin(n)
    
    print("Простое" if r else "Составное")

if __name__ == "__main__":
    main()
