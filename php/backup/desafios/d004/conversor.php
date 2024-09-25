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
            //PEGAR A COTAÇÃO
            $inicio = date("m-d-Y", strtotime("-7 days"));
            $fim = date("m-d-Y");
        
            $url = 'https://olinda.bcb.gov.br/olinda/servico/PTAX/versao/v1/odata/CotacaoDolarPeriodo(dataInicial=@dataInicial,dataFinalCotacao=@dataFinalCotacao)?@dataInicial=\'01-01-2020\'&@dataFinalCotacao=\'01-02-2020\'&$top=1&$orderby=dataHoraCotacao%20desc&$format=json&$select=cotacaoCompra,dataHoraCotacao';
        
            $dados = json_decode(file_get_contents($url), true);
        
            $cotação = $dados["value"][0]["cotacaoCompra"];
            //FIM DA COTAÇÃO
            $dolar = $reais / $cotação;
            $padrao = numfmt_create("pt-BR", NumberFormatter::CURRENCY);
            echo "<p>Seus ". numfmt_format_currency($padrao, $reais, "BRL") . " equivalem a <strong>". numfmt_format_currency($padrao, $dolar, "USD").  "</strong></p>";
            echo "<p><strong>Cotação atualizada de R\$".number_format((float) $cotação, 2, ",", ""). "</strong> retirada diretamente do site oficial do <a href=\"https://www.bcb.gov.br\" target=\"_blank\" rel=\"external\">Banco Central do Brasil</a> .</p>"
        ?>
       <button onclick="javascript:history.go(-1)">Voltar</button>
    </section>
</body>
</html>