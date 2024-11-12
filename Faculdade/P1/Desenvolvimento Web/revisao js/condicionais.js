//Questão 1
let num = -15

if(num > 0){
    console.log("Número positivo e " + (num % 2 == 0 ? "Par." : "Impar."))
}
else if(num < 0){
    console.log("Número negativo.")
}
else{
    console.log("Número igual a zero.")
}

//Questão 2
let idade = 15

if(idade >= 18 && idade <= 65)
    console.log("Pode votar.")
else if(idade > 65)
    console.log("Voto facultativo.")
else
    console.log("Não pode votar.")

//Questão 3
if(idade < 12)
    console.log("Menor de 12 anos.")
else if(idade < 18)
    console.log("Menor de idade.")
