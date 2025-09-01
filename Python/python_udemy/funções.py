def somar(*numeros):
    soma = 0
    for numero in numeros:
        soma += numero

    return soma


def somar(*numeros):
    return sum(numeros)

print(somar(3, 5, 8, 10))

def dividir(numero1 = 1, numero2 = 1):
    return numero1 / numero2

print(dividir())

def mostrar_nome(**nomes):
    return f"Nome: {nomes['fname']}\nSobrenome: {nomes['lname']}"

print(mostrar_nome(fname = "Dante", lname = "Alves"))