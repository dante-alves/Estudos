# Classes
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def __str__(self):
        return f"{self.name}, {self.age}"
    


myObject = Person("Dante", 21)

print(myObject)

# HERANÇA

class Student(Person):
    
    def __init__(self, name, age, rgm):
        super().__init__(name, age) # herdar da classe pai
        self.rgm = rgm

    def __str__(self):
        return super().__str__() + f", {self.rgm}"

myStudent = Student("Breno", 25, 123456789)

print(myStudent)


teste = "cu"

my_itr = iter(teste)

for c in my_itr:
    print(c)

class Sequence:

    # The __iter__() method acts similar to the __init__(), you can do operations (initializing etc.), but must always return the iterator object itself.
    def __iter__(self):
        self.num = 1
        return self
    
    # The __next__() method also allows you to do operations, and must return the next item in the sequence.
    def __next__(self):
        if self.num <= 20:
            next_num = self.num
            self.num += 1

            return next_num
        
        raise StopIteration
    

sequencia = Sequence()

for x in sequencia:
    print(x) # o for utiliza um next(sequencia) para ir de valor em valor dentro do objeto



# POLIMORFISMO

class Vehicle():

    def __init__(self, brand, model):
        self.brand = brand
        self.model = model
    
    def move(self):
        print("Move!")
    
class Car(Vehicle):
    pass

class Boat(Vehicle):
    def move(self):
        print("Sail!")

class Plane(Vehicle):
    def move(self):
        print("Fly!")

car1 = Car("Ford", "Mustang")       #Create a Car object
boat1 = Boat("Ibiza", "Touring 20") #Create a Boat object
plane1 = Plane("Boeing", "747")     #Create a Plane object

for x in (car1, boat1, plane1):
  print(x.brand + ", " + x.model)
  x.move()