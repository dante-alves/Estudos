<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Exercício 1 para casa</title>
    <style>
        body {
            text-align: center;
            font-size: 2em;
        }
    </style>
</head>
<body>
    <!--O preço de um carro novo pro consumidor é a soma do custo de
fábrica com a porcentagem do distribuidor e com os impostos. A
porcentagem do distribuidor e dos impostos são aplicados em cima do
custo de fábrica. As porcentagens encontram-se na tabela a seguir. Faça
um script PHP que contenha uma variável inicializada com o custo de
fábrica de um carro e mostre o preço final ao consumidor.-->

    <h1>Valor do carro</h1>

    <?php 
    $fabrica = $_POST['fabrica'] ?? 0;
    $pDistribuidor = 0;
    $impostos = 0;

    //Atribuindo os valores à porcentagem do distribuidor e aos impostos.
    if ($fabrica < 12000) {
        $pDistribuidor = $fabrica * 0.05;
    } elseif ($fabrica < 25000) {
        $pDistribuidor = $fabrica * 0.10;
        $impostos = $fabrica * 0.15;
    } else {
        $pDistribuidor = $fabrica * 0.15;
        $impostos = $fabrica * 0.20;
    }

    //Cálculo do preço
    $preço = $fabrica + $pDistribuidor + $impostos;

    echo "<p>O valor do carro foi de : R$". number_format($preço, 2, ",", "."). "</p>";

?>
<button onclick="javascript:window.location.href='ex01.html'">Voltar</button>

</body>
</html>
