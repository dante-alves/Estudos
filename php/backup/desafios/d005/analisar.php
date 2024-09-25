<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Analisador de número real</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <section>
        <h1>Analisador de número real</h1>
        <?php 
            $num = $_POST["numero"];
            $whole = (int) $num;
            $decimal = $num - $whole;
            echo "<p>Analisando o número <strong>$num</strong> informado pelo usuário:</p>";
            echo "<ul><li>A parte inteira do número é ". number_format((float)$whole, 0, "", "."). "</li> <li>A parte fracionária do número é ". number_format((float)$decimal, 3, ",", ""). "</li></ul>";
            
        ?>
        <p id="voltar"><a href="javascript:history.go(-1)">Voltar</a></p>
    </section>
</body>
</html>