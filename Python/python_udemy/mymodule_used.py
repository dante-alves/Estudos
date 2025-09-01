# import mymodule forma básica
import mymodule as m # renomeando o módulo

import platform

x = platform.system()
print(x)

m.greetings("Dante")

print(platform.processor())


# como importar só um componente do módulo
from mymodule2 import person1

print(person1)