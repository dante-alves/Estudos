//Questão 1
let a = 10
let b = 16

let soma = a + b 

paridade = (soma % 2 == 0) ? "Par" : "Ímpar"

console.log(`A soma de ${a} e ${b} é igual a ${soma}, e é um número ${paridade}`)

//Questão 2
let resultadoFinal = (((45 / 5) + 7) * 3) - (100/4) 
console.log(`\n${resultadoFinal}`)

//Questão 3
let idade = 17

let eMaiorIdade = (idade > 18 && idade < 65) ? true : false

if(eMaiorIdade)
    console.log("É maior de idade")
else
    console.log("É menor de idade")

//Questão 4
let saudacao = "Bem vindo, "
let nomeUsuario = "Dante"

saudacaoLonga = ((saudacao.concat(nomeUsuario)).length > 12) ? saudacao.concat(nomeUsuario) : saudacao

console.log(saudacaoLonga)