<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Sucessor e Antecessor</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <section>
        <h1>Resultado Final</h1>
        <?php 
            $n = $_GET ["numero"];
            $ant = $n - 1;
            $suc = $n + 1;
            echo "<p>O número escolhido foi <strong>$n</strong></p>";
            echo "<p>O seu antecessor é $ant</p>";
            echo "<p>O seu sucessor é $suc</p>";
        ?>
        <button onclick="history.back()">Voltar</button>
    </section>
</body>
</html>