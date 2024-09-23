<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Sorteador de números</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <section>
        <h1>Trabalhando com números aleatórios</h1>
        <?php 
            $min = $_GET["min"];
            $max = $_GET["max"];
            $numero = rand($min, $max);
            echo "O valor gerado foi <strong>$numero</strong>";
        ?>
         <p>Escolha o valor mínimo e máximo a serem sorteados</p>
         <form action="sorteio.php" method="get">
            <label for="min">Valor mínimo</label>
            <input type="number" name="min" id="idmin">
            <label for="max">Valor máximo</label>
            <input type="number" name="max" id="idmax">
            <input type="submit" value="Gerar número aleatório">
        </form>
    </section>
</body>
</html>