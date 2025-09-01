f = open("eu.txt", "rt")

print(f.read())

f.close()

# OU

with open("eu.txt", "rt") as f:
    print(f.read())

# como ler apenas uma parte do texto

with open("eu.txt", "rt") as f:
    print(f.readline())
    print(f.read(5))
    for x in f:
        print(x) # pega linha por linha