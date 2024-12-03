function tabuada () {
    var numero = document.querySelector('input#numero')
    var res = document.querySelector('select#seltab')
    
    var n1 = Number(numero.value)
    if ( numero.value.trim() == '') { // utilizei numero.value para conseguir pegar a string do elemento numero, e trim() para apagar qualquer espaço em branco que tenha sido colocado acidentalmente na resposta.
        alert('Impossível calcular. Por favor, Digite um número')
        return
    }

    res.innerHTML = ''
    for (var c = 1; c <= 10; c++) {
        var t = n1 * c
        var item = document.createElement('option')
        item.text = `${n1} x ${c} = ${t}`
        item.value = `res${c}`
        res.appendChild(item)
    }
}