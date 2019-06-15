#python3 

def numbervalue(a):
    if a == '0':
        return 6
    elif a == '1':
        return 2
    elif a == '2':
        return 5
    elif a == '3':
        return 5
    elif a == '4':
        return 4
    elif a == '5':
        return 5
    elif a == '6':
        return 6
    elif a == '7':
        return 3
    elif a == '8':
        return 7
    elif a == '9':
        return 6


n = int(input())
numbers = []

for i in range(n):
    numbers.append(str(input()))
    
for word in numbers:
    cont = 0
    for letter in word:
        cont += numbervalue(letter)
    print(str(cont) + ' leds')
