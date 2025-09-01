def myfunc():
    global x # definindo x como global
    x = 300

myfunc() # atribuindo o valor da variável global

print(x) # posso printar x fora do escopo da função pq defini ela como global


y = 200 # aqui primeiro defini a variável de escopo global
def myfunc2():
    global y # chamei a variável y global
    print(y) # printei ela dentro da função, sem passar y como argumento

myfunc2()

def func():
    t = 50
    
    def nested_func():
        nonlocal t # definir que não é uma variável local, mas sim a variável t externa à função
        print(t)

    nested_func()

func()