<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Exercicio 2</title>
    <style>
        body {
            text-align: center;
        }
    </style>
</head>
<body>
    <h1>Exercicio 2</h1>
    <p><strong>Maior ou igual a zero / Menor que zero</strong></p>
    <?php
        $num = $_POST["num"] ?? 0;
        if($num >= 0 ) {
            echo "Numero <strong>$num</strong> é Maior ou Igual a zero.";
        }
        else {
            echo "Numero <strong>$num</strong> é Menor que zero.";
        }
    ?>
    
    </form>
</body>
</html>