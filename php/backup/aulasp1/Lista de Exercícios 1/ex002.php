<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Verificador de números primos</title>
    <style>
        label {
            display: block;
        }
    </style>
</head>
<body>
    
    <?php 
       $valor1 = $_GET ['valor1'] ?? 0;
    ?>

    <form action="<?=$_SERVER['PHP_SELF']?>" method="get">
        <h1>Verificador de números primos</h1>
        <p>
            <label for="valor1">Valor 1</label>
            <input type="number" name="valor1" id="ivalor1" min="1" value="1" step="1">

        </p>
        <p>
        </p>
        <p>
            <input type="submit" value="Verificar">
            <input type="reset" value="Limpar">
        </p>
    </form>

    <?php 
    $divisores = 0;

    for ($i = 1; $i <= $valor1; $i++) {
        if ($valor1 % $i == 0) {
            $divisores++;
        }
    }
    if ($divisores > 2) 
        echo "O número $valor1 não é primo.";
    else 
        echo "O número $valor1 é primo.";
    ?>
</body>
</html>