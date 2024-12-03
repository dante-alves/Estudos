<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Conversor de Moedas v1.0</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <section>
        <h1>Conversor de Moedas v1.0</h1>
        <?php 
            $reais = $_GET["reais"];
            $dolar = $reais / 5.47;
            $padrao = numfmt_create("pt-BR", NumberFormatter::CURRENCY);
            echo "<p>Seus ". numfmt_format_currency($padrao, $reais, "BRL") . " equivalem a <strong>". numfmt_format_currency($padrao, $dolar, "USD").  "</strong></p>";
            echo "<p><strong>Cotação fixa de R\$5,47</strong> informada diretamente no código.</p>"
        ?>
       <button onclick="javascript:history.go(-1)">Voltar</button>
    </section>
</body>
</html>