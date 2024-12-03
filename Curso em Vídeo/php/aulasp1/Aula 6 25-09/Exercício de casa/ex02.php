<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Exercício 2 para casa</title>
    <style>
        body {
            text-align: center;
            font-size: 2em;
        }
    </style>
</head>
<body>
    <!-- Uma agência bancária possui dois tipos de investimentos, conforme o
quadro a seguir. Faça um script PHP que contenha duas variáveis
inicializadas com o tipo de investimento (1 ou 2) e o seu valor,
calculando em seguida seu valor corrigido, de acordo com o tipo de
investimento.
Use o condicional Switch para interpretar o valor da variável tipo de
investimento -->
    <h1>Investimento</h1>
    <?php 

    $tipo = $_POST['tipo'];
    $valor = $_POST['valor'];
    $taxa = 0;
    
    switch ($tipo) {
        case 1: 
            $taxa = 0.03;
            $rendimento = $valor * $taxa;
            $valorFinal = $valor;   
            echo "Investimento do tipo Poupança de R$$valor e com taxa de ". $taxa*100, "%, rendendo R$$rendimento ao mês.";
            echo "<p>Rendimentos em um ano:</p>";
            for ($i = 1; $i <= 12; $i++) {
                $valorFinal += $rendimento; 
                echo "$i". "º mês: R". number_format($valorFinal, 2, ",", "."). "<br>";
             }
        break;
        case 2:
            $taxa = 0.04;
            $rendimento = $valor * $taxa;
            $valorFinal = $valor;
            echo "Investimento do tipo Renda Fixa de R$$valor e com taxa de ". $taxa*100, "%, rendendo R$$rendimento ao mês.";
            echo "<p>Rendimentos em um ano:</p>";
            for ($i = 1; $i <= 12; $i++) {
                $valorFinal += $rendimento; 
                echo "$i". "º mês: R$". number_format($valorFinal, 2, ",", "."). "<br>";
            }
    }
    
    ?>
</body>
</html>