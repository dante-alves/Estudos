<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Calculando Raízes</title>
    <link rel="stylesheet" href="style.css">
<body>
    <?php 
        $n1 = $_GET['n1'] ?? 0;
    ?>

    <main>
        <h1>Calculando Raízes</h1>
        <form action="<?=$_SERVER['PHP_SELF']?>" method="get">
            <label for="n1">Número</label>
            <input type="number" name="n1" id="n1" value="<?=$n1?>">
            <input type="submit" value="Calcular Raízes">
        </form>
    </main>

    <section id="resultado">
        <h2>Resultado Final</h2>
        <?php 
            $Rq = sqrt($n1);
            $Rc = $n1 ** (1/3);
            echo "<p>Analisando o <strong>número $n1</strong>, temos: 
            <ul><li>A sua raiz quadrada é <strong>". number_format((float) $Rq, 3, ",", ".")."</strong></li><li>A sua raiz quadrada é <strong>". number_format((float) $Rc, 3, ",", ".")."</strong></li></ul>";
        ?>
        
    </section>
</body>
</html>