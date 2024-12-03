function clicar() {
    var agora = new Date()
    var anoa = agora.getFullYear() //Ano atual
    var anon = document.querySelector('input#ano') //Ano de nascimento
    var ano = Number(anon.value)
    var res = document.querySelector('div#resultado')
    if (ano == 0 || ano > anoa) {
        window.alert('[ERRO] Verifique os dados e tente novamente.')
    } else {
        var fsex = document.getElementsByName('radsex')
        var idade = anoa - ano
        var gender = ''
        var img = document.createElement('img')
        img.setAttribute('id', 'foto')
        if (fsex[0].checked) {
            gender = 'Homem'
            if (idade < 10) {
                img.setAttribute('src', 'bebeh.jpg')
            } else if (idade < 22) {
                img.setAttribute ('src', 'jovemh.jpg')
            } else if (idade < 55) {
                img.setAttribute ('src', 'adultoh.jpg')
            } else {
                img.setAttribute ('src', 'velhoh.jpg')
            }
        } else if (fsex[1].checked) {
            gender = 'Mulher'
            if (idade < 10) {
                img.setAttribute('src', 'bebem.jpg')
            } else if (idade < 22) {
                img.setAttribute ('src', 'jovemm.jpg')
            } else if (idade < 55) {
                img.setAttribute ('src', 'adultom.jpg')
            } else {
                img.setAttribute ('src', 'velhom.jpg')
            }
        }
        res.style.textAlign = 'center'
        res.innerHTML = (`Detectamos ${gender} com ${idade} anos.`)
        res.appendChild(img)
    }

}