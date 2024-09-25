<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Campo de busca</title>
    <style>
        body {
            text-align: center;
        }

        input {
            margin-bottom: 15px;
        }
    </style>
</head>
<body>
    <?php 
        $lista = ['PERA', 'MAÇÃ', 'UVA', 'MARACUJÁ', 'BATATA', 'BETERRABA', 'ALFACE', 'MELANCIA', 'MAMÃO', 'BANANA', 'ARROZ', 'FEIJÃO', 'PICLES', 'FRANGO', 'CARNE DE GADO', 'MACARRÃO', 'COCA COLA', 'REFRIGERANTE'];

        //Usando OPERADOR TERNÁRIO para a variável $produto receber o produto colocado pelo usuário no input.
        $produto = isset($_POST['produto']) ? trim($_POST['produto']) : ''; 
        // A função ISSET faz o programa verificar se a variável (nesse caso, a $_POST['produto']) está definida, e a função TRIM, serve para o programa ignorar espaços na resposta, pra se eu por exemplo buscar 'MAÇÃ ' com um espaço no final, ele não dizer que não tem o produto na lista.
        
        //Deixando tudo maiúsculo em outra variável, pra que dessa forma, se eu colocar por exemplo Pera, ele vai transformar em PERA, e vai verificar que PERA está na lista. 
        //No teu caso, tu vai utilizar mb_strtolower, como tu colocou a lista em minúsculo.
        $produtov = mb_strtoupper($produto);
    ?>

    <!--Parte do HTML-->
    <h1>Busque por produtos</h1>
    <form method="post">
        <label for="produto"></label>
        <input type="text" name="produto" placeholder="Produto">

        <input type="submit" value="Buscar">
    </form>

    <?php 
        //A função IN_ARRAY vai verificar se o produto ($produtov), está contido no array lista ($lista), e diante disso, foi só fazer uma condicional pra o caso de estar contido na lista, ou não está contido na lista.

            //Caso contido na lista (in_array)
        if (in_array($produtov, $lista)) {
            echo "O produto $produtov está disponível.";
        
            //Nesse caso aqui foi só pra quando iniciar a página, como ainda não vai ter nada definido em produto, ele só vai dar echo de ' ', pra ficar o espaço em branco e só depois aparecer a frase de disponível ou não disponível
        } elseif ($produto == '') {
            echo '';

            //Caso não contido na lista (!in_array)
        } elseif (!in_array($produtov, $lista)) {
            echo "O produto $produtov não está disponível.";
        }
    ?>
</body>
</html>