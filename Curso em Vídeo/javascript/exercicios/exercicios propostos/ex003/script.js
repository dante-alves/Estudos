function contar() {
    var inicio = document.querySelector('input#inicio')
    var fim = document.querySelector('input#fim')
    var passo = document.querySelector('input#passo')
    var res = document.querySelector('div#resultado')

    var i = Number(inicio.value)
    var f = Number(fim.value)
    var p = Number(passo.value)
   
    if (p <= 0) {
        alert('Valor inválido, Considerando passo 1')
        p = 1
    } 
    res.innerHTML = ''
    if (inicio.value.trim() == '' || fim.value.trim() == '') {
        res.innerHTML = ('Impossível Contar...')
        return
    }

    if (i < f) {
        for (var c = i; c <= f; c += p) {
            if (c + p < f) {
                res.innerHTML += (`${c} &#x1F449;`)
            } else {
                res.innerHTML += (`${c} &#x1F6A9;`) //adiciona bandeirinha no final
            }
        } 
        } else {
            for (var c = i; c >= f; c -= p) {
                if (c - p > f) {
                    res.innerHTML += (`${c} &#x1F449;`)
                } else {
                    res.innerHTML += (`${c} &#x1F6A9;`)
                }
            }
    }
}