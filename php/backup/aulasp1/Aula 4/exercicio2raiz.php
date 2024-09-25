<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Exercício 2</title>
</head>
<body>
    <?php 
        $num = $_GET['num']?? 0;
    ?>
    <form action="<?=$_SERVER['PHP_SELF']?>" method="get">
        <h1>Raíz Quadrada</h1>
        <label for="num">Número</label>
        <input type="number" name="num" min="0" step="0.01" required>

        <p><input type="submit" value="Verificar"></p>
    </form>
    
    <?php
    //if ($_SERVER["REQUEST_METHOD"] == "post/get") 
        $raiz = sqrt($num);

        echo "A raiz quadrada de $num é igual a $raiz";
    ?>
</body>
</html>