from functools import reduce
numeros = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

print(list(map(lambda x: x*x, list(filter(lambda x: x % 2 == 0, numeros)))))

nomes = ["Ana", "Bruno", "Carla", "Daniel", "Eva", "Fernanda", "Igor"]

print(list(filter(lambda x: len(x) > 5, nomes)))

precos = [100, 250, 80, 150, 300]
print(list(map(lambda x: x * 0.9, precos)))


numeros = [1, 2, 3, 4, 5]
print(reduce(lambda a, b: a + b, numeros))


palavras = ["banana", "maçã", "uva", "pera"]
#print(list(map(lambda x: x)))

listX = list(map(lambda palavra: ''.join(map(lambda letra: 'x' if letra in "aeiouAEIOU" else letra, palavra)), palavras))

print(listX)


nums = [1, 2, 3, 4, 5]

# resposta: (1, 4), (2, 4), (3, 9), (4, 16), (5, 25)

squared_list = list(map(lambda x: x*x, nums))

final_list = [(x, y) for x, y in zip(nums, squared_list)] # em forma de tuplas com os números
final_list2 = list(map(lambda x: f"({x}, {x*x})",nums)) # em forma de string

print(final_list)

print(final_list2)