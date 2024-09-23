<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Exercício 2</title>
    <style>
        body {
            text-align: center;
        }
    </style>
</head>
<body>
    <?php 
        $celsius = $_GET['celsius']?? 0;
    ?>
    <form action="<?=$_SERVER['PHP_SELF']?>" method="get">
        <h1>Celsius Fahrenheit</h1>
        <label for="celsius">Graus em Celsius</label>
        <input type="number" name="celsius" min="0" step="0.01" required>

        <p><input type="submit" value="Converter"></p>
    </f>
    
    <?php
    //if ($_SERVER["REQUEST_METHOD"] == "post/get") 
        $F = 1.8 * $celsius + 32;
        echo "$F"."º";
    ?>
</body>
</html>