let num = [5, 8, 5, 9, 3]
console.log(`Nosso vetor é ${num}`)
num[5] = 6 //Adicionou 6 na posição 5 do vetor
console.log(`Agora, o vetor é ${num}`)
num.push(7) //O push serve para adicionar o valor entre () na última posição
console.log(`Agora, o vetor é ${num}`)
console.log(`O vetor possui ${num.length} posições.`) //.length serve para indicar o total de posições do vetor
console.log(`Os valores ordenados em ordem crescente são: ${num.sort()}`)//.sort serve para ordenar em ordem crescente os valores do vetor.
console.log(num[3]) //Selecionei o elemento na posição 3



for (let c = 0; c <= num.length; c++) {
    console.log (num[c])
}

for (let c in num) {
    console.log (num[c])
}

//console.log(num.indexOf(5)) // indexOf(valor) procura pelo valor dentro do vetor, e indica a posição dele lá dentro.
let index = 0
for (let c in num) {
    if (num[c] == 5){
        index++
        console.log(`5 foi encontrado na posição ${c}`)
    }
}
console.log(`Ao todo, foram encontrados ${index} valore(s) 5`)