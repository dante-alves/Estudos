# python PEP 8 --> usar a extensão autopep8 para formatação automática
import math

x = 1

print(x)

# variáveis

num_int = 1000 # int
num_float = 4.99 # float
confirmado = False # boolean
texto = "textinho" #string

# strings

# - long string
mensagem = """
Olá, tudo bem? espero que sim!
"""
print(mensagem)

# - funções para string
print(len(texto)) # quantidade de caracteres
print(texto[0]) # primeiro caractere
print(texto[-1]) # vai para o final da string
print(texto[0:3]) # vai do primeiro caractere até o terceiro
print(texto[0:]) # vai até o final
print(texto[:3]) # considera do 0 ao 3

# - formatar strings
first = "Dante"
last = "Alves"
# full = first + " " + last
full = f"{first} {last}"
print(full)

# - métodos para strings -> tudo em python é um objeto, portanto tem métodos
print(texto.upper()) # deixar em maiúsculo
print(texto.lower()) # minúsculo
print(texto.title()) # deixa a primeira letra de cada palavra em maiúsculo
texto = "  textinho"
print(texto.strip()) # remove os espaços em branco 
print(texto.find("xti")) # indica a posição que os caracteres enviados como parâmetro foram encontrados
print(texto.replace("t", "p")) # troca todos os "t" por "p" na variável texto
print("text" in texto) # retorna True se tiver "text" na variável texto, ou False se não

# números

print(10 + 3)
print(10 - 3)
print(10 * 3)
print(10 / 3)
print(10 // 3)
print(10 % 3)
print(10 ** 3)

x += 5

# - trabalhando com números
    # pode usar o import math pra usar várias funções de matemática
print(round(2.9)) # arredonda o número
print(abs(-2.9)) # transforma em absoluto

print(math.ceil(4.9)) # usando do import math

# - conversão de tipos
    # int()
    # float()
    # bool()
    # str()
y = input("y: ") # y vai ser passado como string
z = int(y) + 1 # força y virar inteiro
print(f"y: {y}, z: {z}")

# Falsy value
    # ""
    # 0
    # None

# Operadores de comparação
print(10 > 3)
print(10 < 3)
print(10 == 3)
print(10 != 3)

# Condicionais
temperatura = 24

if temperatura > 30:
    print("Está quente!")
elif temperatura > 23:
    print("Está numa temperatura ok!")
else:
    print("Está frio!")

# Operador Ternário
idade = 18

mensagem = "Maior de idade" if idade >= 18 else "Menor de idade"
print(mensagem)

# Operadores Lógicos
    # and, or, not
rico = True
esperto = True
casado = False

if (rico and esperto) and not casado:
    print("Compra o que quiser")
else:
    print("Não compra o que quiser")

# Limpando operadores de comparação

# idade deve ser entre 18 e 65
idade = 22

#if idade >= 18 and idade < 65
if 18 <= idade < 65:
    print("Tá bom todo")


# For Loops
for num in range(3):
    print("Teste", num + 1, (num + 1) * ".") # um número multiplicado por uma string vai fazer aquela string aparecer X vezes
for num in range(1, 4):
    print("Testando", num, num * ".")

for num in range(1, 10, 2): # o último argumento é para definir de quanto em quanto vai passar
    print("Testando dnv", num, num * ".")


# For..Else
sucesso = True
for num in range(3):
    print("Tentativa")
    if sucesso:
        print("Sucesso!")
        break

# Loops aninhados
for x in range(5):
    for y in range(3):
        print(f"{x}, {y}")

# Iterações
compras = {'Macarrão', 'Bolo', 'Feijão', 'Ovo'}
for item in compras:
    print(item)

# Funções
def soma(num_1, num_2=1): #colocar var=algum valor define um valor padrão a ser usado, caso o argumento não seja passado ao chamar a função
    return num_1 + num_2

print("Soma:", soma(5, num_2=3)) # numa função com muitos argumentos, pode usar a keyword do argumento para facilitar a identificação

# xargs
def multiplica(*numeros): #colocar um argumento com * no início do nome faz com que ele recebe quantos argumentos for 
    produto = 1
    for numero in numeros:
        produto *= numero
    return produto

print(multiplica(5, 3, 8))