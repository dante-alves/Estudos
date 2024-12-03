function carregar () {
var agora = new Date()
var hora = agora.getHours()
var minutos = agora.getMinutes()
var img = window.document.getElementById('foto')
document.querySelector('div#hora').innerHTML = (`Agora são ${hora}:${minutos}!`)
if (hora < 12) {
    document.body.style.background = ('#d0c092')
    img.src = 'ex001/day.jpeg'
} else if (hora < 19){
    document.body.style.background = ('#ff9b20')
    img.src = 'ex001/afternoon.jpg'
} else {
    document.body.style.background = ('#005290')
    img.src = 'ex001/night.jpg'
}
}
