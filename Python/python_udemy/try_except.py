try:
    print(x)
except NameError:
    print("Variável X não declarada.")


isFloat = False

while not isFloat:
    
    try:
        x = float(input("Insira um número: "))
        isFloat = True
    except:
        print("Valor inválido!")
    
print(x)