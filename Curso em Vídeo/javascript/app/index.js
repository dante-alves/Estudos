// () => {} é uma arrow function
const { select, input, checkbox } = require('@inquirer/prompts')
const fs = require ("fs").promises

let mensagem = "Bem vindo ao app de Metas";

let metas 

const carregarMetas = async () => {
    try {
        const dados = await fs.readFile("metas.json", "utf-8")
        metas = JSON.parse(dados)
    }
    catch (erro) {
        metas = []
    }
}

const salvarMetas = async () => {
    await fs.writeFile("metas.json", JSON.stringify(metas, null, 2))
}

// função de cadastrar metas
const cadastrarMeta = async () => {
    const meta = await input ({message: "Digite a meta:"})

    if (meta.length == 0) {
        mensagem = "A meta não pode ser vazia."
        return
    }
    
    metas.push (
        { value: meta, checked: false }
    )

    mensagem = "Meta cadastrada com sucesso!"
}

// função de listar metas
const listarMetas = async () => {

    if (metas.length == 0) {
        mensagem = "Não existem metas."
        return
    }

    const respostas = await checkbox ({
        message: "Use as setas para mudar de meta, o espaço para marcar ou desmarcar e o Enter para finalizar essa etapa",
        choices: [...metas],
        instructions: false,
    })
    
    metas.forEach((m) => {
        m.checked = false

    if (respostas.length == 0) {
        mensagem = "Nenhuma meta selecionada!"
        return
    }

    mensagem = `${respostas.length} meta(s) concluída(s)!`

    })

    respostas.forEach((resposta) => {
        const meta = metas.find((m) => {
            return m.value == resposta
        })
        meta.checked = true
    })

    console.log ('Meta(s) concluída(s)')
}

// função de mostrar metas realizadas 
const metasRealizadas = async () => {

    if (metas.length == 0) {
        mensagem = "Não existem metas."
        return
    }

    const realizadas = metas.filter((meta) => {
        return meta.checked
    })

    if (realizadas.length == 0) {
        mensagem = "Não existem metas realizadas por enquanto!"
        return
    }

    await select ({
        message: `Metas Realizadas: ${realizadas.length}`,
        choices: [...realizadas]
    })
}

// função de metas em aberto
const metasAbertas = async () => {

      if (metas.length == 0) {
        mensagem = "Não existem metas."
        return
    }

    const abertas = metas.filter((meta) => {
        return !meta.checked
    })

    if (abertas.length == 0) {
        mensagem = "Não existem metas em aberto, parabéns!"
        return
    }

    await select ({
        message: `Metas em aberto: ${abertas.length}`,
        choices: [...abertas]
    })
}

// função de deletar metas
const deletarMetas = async () => {

    if (metas.length == 0) {
        mensagem = "Não existem metas."
        return
    }

    const metasDesmarcadas = metas.map ((meta) => {
        return { value: meta.value, checked: false }
    })
    const itensDeletar = await checkbox ({
        message: "Selecione meta para deletar",
        choices: [...metasDesmarcadas],
        instructions: false,
    })

    if (itensDeletar == 0) {
        mensagem = "Nenhum item deletado."
        return
    }

    itensDeletar.forEach((item) => {
        metas = metas.filter((meta) => {
            return meta.value != item
        })
    })

    mensagem = "Meta(s) deletada(s) com sucesso!"
}

// função de mensagens
const mostrarMensagem = () => {
    console.clear();
    
    if (mensagem != "") {
        console.log(mensagem)
        console.log("")
        mensagem = ""
    }
}
// função que inicia o menu de aplicação
const start = async () => { //async para fazer o await funcionar
    await carregarMetas ()
    while (true) {
        mostrarMensagem()
        await salvarMetas

        const opcao = await select ({
            message: "Menu >",
            choices: [
                {
                    name: "Cadastrar meta",
                    value: "Cadastrar"
                },
                {
                    name: "Listar metas",
                    value: "Listar"
                },
                {
                    name: "Metas Realizadas",
                    value: "Realizadas"
                },
                {
                    name: "Metas em Aberto",
                    value: "Abertas"
                },
                {
                    name: "Deletar Metas",
                    value: "Deletar"
                },
                {
                    name: "Sair",
                    value: "Sair"
                }

            ]
        }) 
        //Seleção de opções     
        switch (opcao) {
            case "Cadastrar":
                await cadastrarMeta()
                await salvarMetas()
                break
            case "Listar":
                await listarMetas()
                await salvarMetas()
                break
            case "Realizadas":
                await metasRealizadas()
                break
            case "Abertas":
                await metasAbertas()
                break
            case "Deletar":
                await deletarMetas()
                break
            case "Sair":
                console.log ("Até a próxima!")
                return
        }
    }
}

start ()