<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Exercício</title>
    <style>
        body {
            text-align: center;
        }
    </style>
</head>
<body>
    <h2>Salário Total</h2>
        <?php 
            function salTotal($salario, $apurado) {
                $comissao = $apurado * 0.04;
                $salTotal = $salario + $comissao;
                return "<p>Comissão: R$". number_format($comissao, 2, ",", "."). "</p> <p>Salário Total: R$". number_format($salTotal, 2, ",", "."). "</p>";
            }

            echo salTotal($salario = $_GET['sal'] ?? 0, $apurado = $_GET['apurado'] ?? 0);
        ?>
</body>
</html>