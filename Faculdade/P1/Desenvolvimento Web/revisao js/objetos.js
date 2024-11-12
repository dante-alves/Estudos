//Questão 1
let pessoa = {
    nome: "Dante",
    idade: 21,
    cidade: "João Pessoa",
    hobbies: ["Jogar", "Assistir filmes", "Treinar"],

    mostrarHobby: function(){
        return this.hobbies[1]
    },

}

console.log(pessoa)

pessoa.cidade = "Manaíra"

pessoa.profissao = "Estudante"

console.log(pessoa)
