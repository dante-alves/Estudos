<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Salário Mínimo</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <?php 
        $padrao = numfmt_create("pt-BR", NumberFormatter::CURRENCY);
        $salario_min = 1412.00;
        $salario = $_GET['sal'] ?? 0;
    ?>

    <main>
        <h1>Informe seu salário</h1>
        <form action="<?=$_SERVER['PHP_SELF']?>" method="$_GET">
            <label for="sal">Salário (R&#36;)</label>
            <input type="number" name="sal" id="sal" value="<?=$salario?>" step="0.01">
            <input type="submit" value="Calcular">
        </form>
    </main>

    <section>
        <h2>Resultado Final</h2>        
        <?php 
            $whole = (int)$salario;
            $centavos = $salario - $whole;
            $quantos = $salario / $salario_min;
            $diferenca = $salario % $salario_min;
            $diferenca_total = $diferenca + $centavos;
            echo "<p>Quem recebe um salário de ".numfmt_format_currency($padrao, $salario, "BRL"). " ganha <strong>". (int)$quantos. " salários mínimos</strong> + ".numfmt_format_currency($padrao, $diferenca_total, "BRL"). "</p>"
        ?>
    </section>
</body>
</html>