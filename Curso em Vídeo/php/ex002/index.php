<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Testando a hora</title>
</head>
<body>
    <?php 
        date_default_timezone_set("America/Sao_Paulo");
        echo "Hoje é dia ". date("d/m/Y");
        echo " e agora são exatamente ". date("G:i:s");  
    ?>
</body>
</html>