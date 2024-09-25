<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Exercício 3</title>
</head>
<body>
    <h1>Utilizando array associativo</h1>
    <?php 
    //Array associativo
    $produto = array(
        "Cadeira" => array(250, 10),
        "Mesa" => array(750,5),
        "Sofá" => array(1500, 2)
    );

    $total = array(
        "cadeiras" => $produto["Cadeira"][0] * $produto["Cadeira"][1],
        "mesas" => $produto["Mesa"][0] * $produto["Mesa"][1],
        "sofás" => $produto["Sofá"][0] * $produto["Sofá"][1]
    );

    $totalTudo = $total['cadeiras'] + $total['mesas'] + $total['sofás'];

    echo "Valor total das cadeiras: $total[cadeiras]<br>";
    echo "Valor total das mesas: $total[mesas]<br>";
    echo "Valor total dos sofás: $total[sofás]<br>";
    echo "Valor total de tudo: $totalTudo";
    ?>
</body>
</html