# ------- LISTAS ------- 
cidade = []

# adicionar itens
cidade.append('São Paulo')
cidade.insert(0, 'Rio de Janeiro')
cidade.insert(1, 'João Pessoa')

cidade[1:2] = 'Diamante', 'Manaíra'
print(cidade)

# adicionar os elementos de uma lista à outra
lista = ['Itaporanga', 'Itapipoca', 'Taperoá', 'Teixeira']
cidade.extend(lista)

print(cidade)
# remover itens
lista.remove('Itaporanga')
print(lista)
lista.pop(0)
print(lista)
lista.pop()
print(lista)

del lista # deleta a lista 

lista = ['Itaporanga', 'Itapipoca', 'Taperoá', 'Teixeira']

lista.clear() # limpa a lista, mas não deleta ela
print(lista)

# loop na lista
for x in cidade:
    print(x)

print('-----------------')
# usando o índice
for i in range(len(cidade)):
    print(cidade[i])

print('-----------------')
# usando list comprehension
newList = []

""" for x in cidade:
    if 'a' in x:
        newList.append(x) """

# newlist = [expression - for - item - in - iterable - if - condition == True]

newList = [x for x in cidade if 'a' in x]

print(newList)

newList2 = [x for x in range(8) if x % 2 == 0]

print('-----------------\n', newList2)

newList3 = [x.upper() for x in newList]
print('-----------------\n', newList3)

# substituir um valor por outro
newList4 = [x if x != "Diamante" else "Bosta" for x in newList]
print('-----------------\n', newList4)

# usando o método sort()
newList4.sort()
print('-----------------\n', newList4)

# ordenando ao contrário
listaOrdenada = [15, 25, 35, 10, 20, 5, 30]
listaOrdenada.sort(reverse=True)
print(f"-----------------\n {listaOrdenada}")

# definindo uma condição para ordenar
def mySort(n):
    return abs(n - 25)

listaOrdenada.sort(key = mySort)

print(listaOrdenada)

# copiar uma lista
lista1 = listaOrdenada.copy()
lista1 = list(listaOrdenada)
lista1 = listaOrdenada[:] # slice

# juntar duas listas
lista2 = lista + lista1

for x in lista1:
    lista2.append(x)

lista2.extend(lista1)

# --------------------------- TUPLAS --------------------------- 
    # são ordenadas e imutáveis
tupla = ("bosta", "fezes", "cocô", "xixi", "fezes")
print(type(tupla))

# gambiarra pra modificar tuplas
listaTemp = list(tupla)
listaTemp[1] = "mijo"
tupla = tuple(listaTemp)
print(f"-----------------------\n{tupla}")

# como adicionar itens a uma tupla
    # ou transformando em lista e alterando, ou concatenando tuplas

tupla2 = ("pipi",)

tupla2 += tupla

print(f"-----------------------\n{tupla2}")

# remover itens da tupla -> transformar em lista, ou deletar a tupla completa

del tupla2 # deletar uma tupla

# como dar unpack numa tupla
(dejeto1, dejeto2, dejeto3, *dejetos) = tupla # *dejetos é para enviar demais valores existentes na tupla para uma lista

print(f"------------------\n{dejeto1}, {dejeto2}, {dejeto3}, {dejetos}")

print(f"índice de cocô: {tupla.index("cocô")}")

# --------------------------- SETS ---------------------------------
    # sets são imutáveis e desordenados 

novoSet = {"banana", "maçã", "abacaxi"}

for x in novoSet: print(x)

# adicionando valores
novoSet.add("pêra")

for x in novoSet: print(x)

novoSet2 = {"melancia", "tomate"}

novoSet.update(novoSet2) # o update não precisa ser outro set, pode adicionar uma lista, ou tupla, por exemplo

print(novoSet)

# removendo valores
novoSet.remove("maçã") # se o valor não existir, gera um erro
novoSet2.discard("tomate") # se o valor não existir, não gera um erro
print(novoSet.pop()) # remove um valor aleatório e retorna qual valor foi removido

novoSet.clear() # limpa o set
del novoSet2 # deleta o set

print(novoSet)

# join Sets
""" The union() and update() methods joins all items from both sets. -----> pode ser usado o operador | para substituir o union ex set1 | set 2 

The intersection() method keeps ONLY the duplicates. ------> pode ser substituído por & ex: set1 & set2
-------> tem também o intersection_update() que não retorna um novo set, mas sim atualiza o próprio set

The difference() method keeps the items from the first set that are not in the other set(s). ------> pode ser substituído pelo operador -

The symmetric_difference() method keeps all items EXCEPT the duplicates. --------> pode ser substituído pelo operador ^    """


# --------------------------- DICIONÁRIO --------------------------- 
dicionario = {
    "marca": "Ford",
    "modelo": "Mustang",
    "year": 1964
}

print(dicionario["modelo"])


dicionario2 = dict(name = "Dante", age = 21, gender = "M")

print(dicionario2["name"])

# como ver as chaves de um dicionário
x = dicionario2.keys() # retorna uma lista com as chaves

print(x)
dicionario2["country"] = "Brazil" # se o dicionário for atualizado, a lista automaticamente atualiza
print(x)


# como ver os valores de um dicionário

y = dicionario2.values()
print(y)

# como ver itens no dicionário

z = dicionario2.items()
print(z)

# verificar a existência de uma chave no dicionario

if "country" in dicionario2: print("Existe")


if "Dante" in dicionario2["name"]: print("Existe") 
else: print("Não existe")

# como atualizar um valor
    #direto
dicionario2["name"] = "Breno"

    #método update()
dicionario2.update({"name": "Dante"})

print(dicionario2["name"])

# adicionar valor
    #direto
dicionario2["weight"] = 65.5

    #método update()
dicionario2.update({"height": 1.67})

print(dicionario2)

# dicionário aninhado
dicionario3 = {
    "pessoa1" : { 
        "nome" : "Paulo",
        "idade" : 22
    },

    "pessoa2" : {
        "nome" : "Dante",
        "idade" : 21
    }
}


# outra forma
pessoa1 = {
    "nome" : "Paulo"
}

pessoa2 = {
    "nome" : "Dante"
}

dicionario4 = {
    "pessoa1" : pessoa1,
    "pessoa2" : pessoa2
}

print(dicionario3)
print(dicionario3["pessoa1"])
print(dicionario3["pessoa1"]["nome"])

print(dicionario4)

# loop no dicionario aninhado

print(f"\nloop\n")
for x, item in dicionario3.items():
    print(x)
    for componente in item:
        print(componente + ' : ', item[componente])

