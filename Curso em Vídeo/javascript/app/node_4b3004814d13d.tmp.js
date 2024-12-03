const { select } = require('@inquirer/prompts')

// () => {} é uma arrow function
const start = async () => { //async para fazer o await funcionar
    while (true) {
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
                    name: "Sair",
                    value: "Sair"
                }

            ]
        }) 
            
        switch (opcao) {
            case "Cadastrar":
                console.log ("Vamos cadastrar!")
                break
            case "Listar":
                console.log ("Vamos listar!")
                break
            case "Sair":
                console.log ("Até a próxima!")
                return
        }
    }
}

start ()