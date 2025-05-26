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


# ------- DICIONÁRIO ------- 

# -------  ------- 