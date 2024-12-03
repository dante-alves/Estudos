<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Conversor de reais para dólar</title>
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
        <h1>Conversor de reais para dólar</h1>
        <p>
            <label for="valor1">Valor em reais R$</label>
            <input type="number" name="valor1" id="ivalor1" min="0" step="0.01" autocomplete="off">

        </p>
        <p>
        </p>
        <p>
            <input type="submit" value="Verificar">
            <input type="reset" value="Limpar">
        </p>
    </form>

    <?php 
    $dolar = $valor1 / 5.49;

    echo "O valor em dólar é de U$ ". number_format($dolar, 2, ",", ".");
    ?>
</body>
</html>