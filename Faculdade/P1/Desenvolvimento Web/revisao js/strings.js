//Questão 1
let hello = "Olá" +" " + "Mundo" + "!"
console.log(hello)

//Questão 2

let string = "123.45"
let decimal = parseFloat(string)
let inteiro = Math.round(decimal)

console.log(inteiro)

//Questão 3

let js = "Javascript"
let ultimasLetras = js.slice(-2).toUpperCase()

let palavraAlterada = js.slice(0, -2) + js.slice(-2).toUpperCase()

console.log(ultimasLetras)

console.log(palavraAlterada)
