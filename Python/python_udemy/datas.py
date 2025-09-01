import datetime as d

x = d.datetime.now()

print(x)
print(x.year)
print(x.month)
print(x.day)
print(x.strftime("%A"))

y = x.strftime("%d/%m/%Y")

print(y)