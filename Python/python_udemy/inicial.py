# strings
nome = "Dante"
print(len(nome))

for x in nome:
    if x == 'a':
        print(x)


if "ant" in nome:
    print('tem')

if "cu" not in nome:
    print('não tem')
# slice
print(nome[:2])
print(nome[-4:-2])
# métodos para Strings
print(nome.upper())
print(nome.lower())

print("índice da letra \"n\" = " + str(nome.find("n")))

print(nome.replace('a', 'e'))

valor = int(input("Insira um valor: "))
print(valor)

# parâmetro Default
def soma(num1, num2=5):
    return num1 + num2

print(soma(8))

def printar(string):
    return f'Texto: ' + string

print(printar("Três tigres comeram três potes de trigo"))

# xargs

def soma_x(*numeros):
    soma = 0
    for num in numeros:
        soma += num
    
    return soma

print(soma_x(5, 8, 11, 14))

# xargs definindo os parâmetros na chamda
def agencia(**carro): # utiliza 2 asteriscos
    return carro


print(agencia(motor='penis', modelo='Gol Bola', cor='Verde'))
print(type(agencia(motor='penis', modelo='Gol Bola', cor='Verde')))

def fatorial(numero):
    fatorial = 1
    while numero > 1:
        fatorial *= numero
        numero-=1
    
    return fatorial

import math
print(math.factorial(4))
print(fatorial(4))