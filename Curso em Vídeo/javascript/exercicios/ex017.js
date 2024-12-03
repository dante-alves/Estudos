let v = 12

function parimp(n) {
    if (n % 2 == 0) {
        return 'PAR'
    } else {
        return 'ÍMPAR'
    }
}

let res = parimp(v)
console.log(`${v} é ${res}`)

//Também pode ir direto, sem puxar pra uma variável:
console.log(parimp(5))

function soma(n1=0, n2=0) { //Se colocar um valor padrão pro parâmetro, ele é colocado quando eu não defino um valor para determinado parâmetro.
    return n1 + n2
}

console.log(soma(1, 5))

let f = function fatorial (x) {
    return x * 2
}
console.log(f(6))

function fat (n) { //fatorial
    let fat = 1
    for (let c = n; c > 1; c--) {
        fat *= c 
    }
    return fat
}

console.log(fat(5))

function fatorial (n) {
    if (n == 1) {
        return 1
    } else {
        return (n * fatorial (n - 1))
    }
}

console.log(fatorial(1))