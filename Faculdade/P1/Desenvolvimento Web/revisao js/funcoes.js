//Questão 1
function soma(a, b){
    if(a + b > 100)
        return "Soma elevada"
    else
        return a+b
}

num1 = 35
num2 = 87

console.log(soma(num1, num2))

//Questão 2
function ehPrimo(num){
    let divisores = 0

    for(let i = 1; i <= num; i++){
        if(num % i === 0){
            divisores++
        }
    }

    return divisores === 2
}

let numero = 13

console.log(ehPrimo(numero) ? `O número ${numero} é primo` : `O número ${numero} não é primo`)