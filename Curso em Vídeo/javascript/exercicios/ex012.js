var agora = new Date()
var hora = agora.getHours ()
var minutos = agora.getMinutes ()
if (hora < 5) {
    console.log (`Agora são exatamente ${hora}:${minutos} da madrugada. Boa madrugada!`)
} else if (hora < 12) {
    console.log (`Agora são exatamente ${hora}:${minutos} da manhã. Bom dia!`)

} else if (hora < 19) {
    console.log (`Agora são exatamente ${hora}:${minutos} da tarde. Boa tarde!`)
} else {
    console.log (`Agora são exatamente ${hora}:${minutos} da noite. Boa noite!`)
} 