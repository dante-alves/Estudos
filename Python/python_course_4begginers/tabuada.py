print("         TABUADA    ")
print("     ---------------")

# coletar o número
x = int(input("     De qual número deseja saber a tabuada? "))

# fazer a verificação
while x < 0 or x > 10:
    x = int(input("     Valor não permitido. Insira um valor entre 0 e 10! "))

# seguir para a tabuada quando o valor for permitido
#for i in range(0, 11):
i = 0
while i <= 10:
    print(f"     {x} X {i} = {x * i}")
    i += 1