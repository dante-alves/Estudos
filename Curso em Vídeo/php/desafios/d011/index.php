<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Reajustador de preços</title>
    <link rel="stylesheet" href="style.css">
<body>
    <?php 
        $padrao = numfmt_create("pt-BR", NumberFormatter::CURRENCY);
        $p = $_GET['p'] ?? 0;
        $reajuste = $_GET['reaj'] ?? 0;
    ?>

    <main>
        <h1>Reajustador de preços</h1>
        <form action="<?=$_SERVER['PHP_SELF']?>" method="get">
            <label for="p">Preço do produto (R&#36;)</label>
            <input type="number" name="p" id="p" value="<?=$p?>" step="0.01">
            <label for="reaj">Qual será o percentual do reajuste? <strong><span id="porcent"><?=$reajuste?></span>%</strong></label>
            <input type="range" name="reaj" id="reaj" min="0" max="100" value="<?=$reajuste?>" step="1" oninput="mudaValor()">
            <input type="submit" value="Reajustar">
        </form>
    </main>

    <section id="resultado">
        <h2>Resultado do Reajuste</h2>
        <?php 
            $reajustado = $p + ($p * ($reajuste/100));
            echo "<p>O produto que custava ". numfmt_format_currency($padrao, $p, "BRL"). ", com <strong>$reajuste&#37; de aumento</strong>, vai passar a custar <strong>". numfmt_format_currency($padrao, $reajustado, "BRL"). "</strong> </p>";
        ?>
    </section>

    <script>
        function mudaValor () {
            porcent.innerText = reaj.value
        }
        
        
    </script>
</body>
</html>