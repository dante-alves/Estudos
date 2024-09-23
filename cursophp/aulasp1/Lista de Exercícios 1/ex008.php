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

        //Usando operador ternário para 
        $produto = isset($_POST['produto']) ? trim($_POST['produto']) : '';
        
        //Deixando tudo maiúsculo
        $produtov = mb_strtoupper($produto);
    ?>
    <h1>Busque por produtos</h1>
    <form method="post">
        <label for="produto"></label>
        <input type="text" name="produto" placeholder="Produto">

        <input type="submit" value="Buscar">
    </form>
    <?php 
        if (in_array($produtov, $lista)) {
            echo "O produto $produtov está disponível.";
        } elseif ($produto == '') {
            echo '';
        } elseif (!in_array($produtov, $lista)) {
            echo "O produto $produtov não está disponível.";
        }
    ?>
</body>
</html>