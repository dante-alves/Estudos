<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Calculador de idade</title>
    <link rel="stylesheet" href="style.css">
<body>
    <?php 
        $anoAtual = date('Y');
        $nascimento = $_GET['nascimento'] ?? 2000;
        $anoFinal = $_GET['anoFinal'] ?? $anoAtual;
    ?>

    <main>
        <h1>Calculador de idade</h1>
        <form action="<?=$_SERVER['PHP_SELF']?>" method="get">
            <label for="nascimento">Em que ano você nasceu?</label>
            <input type="number" name="nascimento" id="nascimento" min="1900" max="<?=$anoAtual?>" value="<?=$nascimento?>">
            <label for="anoFinal">Quer saber sua idade em que ano? Atualmente estamos em <strong><?=$anoAtual?></strong></label>
            <input type="number" name="anoFinal" id="anoFinal" min="<?=$nascimento?>" value="<?=$anoFinal?>">
            <input type="submit" value="Qual será minha idade?">
        </form>
    </main>

    <section id="resultado">
        <h2>Resultado</h2>
        <?php 
            $idade = $anoFinal - $nascimento;
            echo "<p>Quem nasceu em $nascimento vai ter <strong>$idade anos</strong> em $anoFinal.</p>";
        ?>
        
    </section>
</body>
</html>