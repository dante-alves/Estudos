<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Exercicio 1</title>
    <style>
        body {
            text-align: center;
        }
    </style>
</head>
<body>
    <h1>Exercicio 1</h1>
    <p><strong>Positivo / Negativo / Nulo</strong></p>
    <form method="post">
        <p>
            <label for="numero">Digite um numero:</label>
            <input type="number" name="num" id="num" placeholder="0" required>
            <input type="submit" value="Enviar">
        </p>

    <?php
        
        $num = $_POST["num"] ?? 0;
        if($num == 0 ) {
            echo "Numero <strong>$num</strong> é NULO!";
        }
        else if($num >= 1) {
            echo "Numero <strong>$num</strong> é POSITIVO";
        }
        else {
            echo "Numero <strong>$num</strong> é NEGATIVO";
        }
    ?>
    
    </form>
</body>
</html>