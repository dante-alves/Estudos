<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Calculadora de Tempo</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <?php 
        $sec = $_GET['sec'] ?? 0;
    ?>

    <main>
        <h1>Calculadora de Tempo</h1>
        <form action="<?=$_SERVER['PHP_SELF']?>" method="$_GET">
            <label for="sec">Qual é o total de segundos?</label>
            <input type="number" name="sec" id="sec" value="<?=$sec?>">
            <input type="submit" value="Calcular">
        </form>
    </main>

    <section>
        <h2>Totalizando tudo</h2>        
        <?php 
            $semanas = intdiv($sec, 604800);
            $dias = intdiv(($sec % 604800), 86400);
            $horas = intdiv(($sec % 86400), 3600);
            $min = intdiv(($sec % 3600), 60);
            $resto_sec = ($sec % 60);
            echo "<p>Analisando o valor que você digitou, <strong>". number_format($sec, 0, "", "."). " segundos</strong> equivalem a um total de:</p> 
            <ul>
                <li>$semanas semanas</li>
                <li>$dias dias</li>
                <li>$horas horas</li>
                <li>$min minutos</li>
                <li>$resto_sec segundos</li>
            </ul>
            " 
        ?>
    </section>
</body>
</html>