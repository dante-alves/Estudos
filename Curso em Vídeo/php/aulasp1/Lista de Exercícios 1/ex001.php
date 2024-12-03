<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Calculadora Simples</title>
    <style>
        label {
            display: block;
        }
    </style>
</head>
<body>
    
    <?php 
       $valor1 = $_GET ['valor1'] ?? 0;
       $valor2 = $_GET ['valor2'] ?? 0;
       $operacao = $_GET ['operacao'] ?? '';
    ?>

    <form action="<?=$_SERVER['PHP_SELF']?>" method="get">
        <h1>Calculadora Simples</h1>
        <p>
            <label for="valor1">Valor 1</label>
            <input type="number" name="valor1" id="ivalor1" value="0" step="0.01">
            <label for="valor2">Valor 2</label>
            <input type="number" name="valor2" id="inota2" value="0" step="0.01">
        </p>
        <p>
        </p>
        <p>
            <input type="submit" name="operacao" value="Somar">
            <input type="submit" name="operacao" value="Subtrair">
            <input type="submit" name="operacao" value="Multiplicar">
            <input type="submit" name="operacao" value="Dividir">

            <input type="reset" value="Limpar">
        </p>
    </form>

    <?php 

       switch ($operacao) {
        case 'Somar':
            $resultado = $valor1 + $valor2;
            echo "A soma entre $valor1 e $valor2 é igual a $resultado";
            break;

        case 'Subtrair':
            $resultado = $valor1 - $valor2;
            echo "A subtração entre $valor1 e $valor2 é igual a $resultado";
            break;

        case 'Multiplicar':
            $resultado = $valor1 * $valor2;
            echo "A multiplicação entre $valor1 e $valor2 é igual a $resultado";
            break;
        case 'Dividir':
            if ($valor1 == 0)
                echo "O dividendo não pode ser 0. Insira um novo valor.";
            else {
            $resultado = $valor1 / $valor2;
            echo "A divisão entre $valor1 e $valor2 é igual a $resultado";
            }
            break;
       }

    ?>
</body>
</html>