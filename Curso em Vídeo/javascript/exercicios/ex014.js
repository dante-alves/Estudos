//REPETIÇÕES 1

var c = 1 //Contador
var n1 = 2 
//Estrutura de Repetição com teste lógico no final
do {
    var r = n1 * c
    console.log(`${n1} x ${c} = ${r}`)
    c++
} while (c <= 10)

/* Estrutura de Repetição com teste lógico no início
while (c <= 10) {
    var r = n1 * c //Multiplicação
    console.log(`${n1} x ${c} = ${r}`) //Resultado
    c++
}
*/