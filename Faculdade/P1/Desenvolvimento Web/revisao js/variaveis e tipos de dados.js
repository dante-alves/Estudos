//Questão 1
let nomeCompleto = "DANTE ALVES E SILVA"

let nomeFormatado = nomeCompleto.toLowerCase().replace(/\b\w/g, letra => letra.toUpperCase())

console.log(nomeFormatado)

//Questão 2
let anoNascimento = 2003

let data = new Date()
let anoAtual = data.getFullYear()

let idade = anoAtual - anoNascimento

console.log(`\nVocê tem ${idade} anos`)

//Questão 3

let ehEstudante = false

let statusEstudante = (ehEstudante) ? "Aluno" : "Não Aluno"

console.log(`\nStatus de Estudante: ${statusEstudante}`)