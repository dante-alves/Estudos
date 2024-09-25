<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Me livrando da maldição</title>
</head>
<body>
    
        <?php 
        print "<h1>Olá, mundo! \u{1f30e}</h1>";
        $nome = "Dante";
        print "<p>O meu nome é $nome</p>";
        ?>

        <?= "<p>O meu nome é $nome</p>"?>
  
    <p>Vamos tentar nos livrar da maldição!</p>    

</body>
</html>