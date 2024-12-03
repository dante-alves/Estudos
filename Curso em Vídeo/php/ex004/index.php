<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Strings</title>
</head>
<body>
    <h1>Testes com Strings</h1>
    <?php 
        $nome = "Dante";
        $sobrenome = "Alves";
        $apelido = "Minotauro";
        const ESTADO = "Paraíba";
        echo "$nome $sobrenome \u{1F596} \n";
        echo "Eu moro na ". ESTADO ;
        echo "\n $nome \"Minotauro\" $sobrenome"; 
    ?>
</body>
</html>