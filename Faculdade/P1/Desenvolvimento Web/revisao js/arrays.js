//Questão 1
let coresPrimarias = ["Vermelho", "Azul", "Verde"]
let coresSecundarias = ["Amarelo", "Roxo"]

let todasCores = coresPrimarias.concat(coresSecundarias)

console.log(todasCores) 

//Questão 2
todasCores.unshift("Laranja")

console.log(todasCores)

//Questão 3
let corEscolhida = todasCores[2]

console.log(corEscolhida)

//Questão de Manipulação de arrays

let corRemovida = todasCores.pop()

let primeiraCorRemovida = todasCores.shift()

console.log(corRemovida)
console.log(primeiraCorRemovida)