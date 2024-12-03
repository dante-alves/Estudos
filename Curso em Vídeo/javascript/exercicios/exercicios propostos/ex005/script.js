var v =[]
var menorV = 0
var maiorV = 0
var f = document.querySelector('div#finalizado')

function isNumero(n) {
    if (Number(n) >= 1 && Number(n) <= 100) {
        return true
}   else {
        return false
}
}
function inLista (n, l) {
    if (l.indexOf(Number(n)) != -1) {
        return true
    } else {
        return false
    }
}
function adicionar () {
    var numero = document.querySelector('input#numero')
    var res = document.querySelector('select#selval')
    
    var n1 = Number(numero.value)
    if ( numero.value.trim() == '') { 
        alert('Impossível adicionar. Por favor, digite um número')
        return
    }
    
    if (isNumero(numero.value) && !inLista(numero.value, v)) {
        v.push(n1)
        var item = document.createElement('option')
        item.text = `Valor ${n1} adicionado.`
        res.appendChild(item)
        f.innerHTML = ''
    
        if (maiorV < n1) {
            maiorV = n1
        }
    
        if (menorV == 0) {
            menorV = n1
        } else if (menorV > n1) {
            menorV = n1
        }
        numero.value = ''
        
    } else {
        window.alert('Valor inválido ou já encontrado na lista!')
        numero.value = ''
    }
}
function soma () {
    var s = 0
    for (var c = 0; c < v.length; c++) {
        s += v[c]  
    }
    return (s)
}

function finalizar () {
    if (v.length == 0) {
        alert('Impossível calcular. Por favor, insira ao menos um número')
        return        
    }
    
    f.innerHTML += `<p>Ao todo, temos ${v.length} números cadastrados.</p>`
    f.innerHTML += `<p>O maior valor informado foi ${maiorV}</p>`
    f.innerHTML += `<p>O menor valor informado foi ${menorV}.</p>`
    f.innerHTML += `<p>Somando todos os valores, temos ${soma()}.</p>`
    f.innerHTML += `<p>A média dos valores digitados é ${soma()/v.length}.</p>`

    /*var f = document.querySelector('div#finalizado')
    var novoP = document.createElement('p')
    novoP.textContent = `Ao todo, temos ${v.length} números cadastrados.`
    f.appendChild(novoP)
    
    var novoP = document.createElement('p')
    novoP.textContent = `O maior valor informado foi ${maiorV}.`
    f.appendChild(novoP)

    var novoP = document.createElement('p')
    novoP.textContent = `O menor valor informado foi ${menorV}.`
    f.appendChild(novoP)

    var novoP = document.createElement('p')
    novoP.textContent = `Somando todos os valores, temos ${soma()}.`
    f.appendChild(novoP)

    var novoP = document.createElement('p')
    novoP.textContent = `A média dos valores digitados é ${soma()/v.length}.`
    f.appendChild(novoP)*/
}