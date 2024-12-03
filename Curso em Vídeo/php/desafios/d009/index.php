<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Médias Aritméticas</title>
    <link rel="stylesheet" href="style.css">
<body>
    <?php 
        $n1 = $_GET['n1'] ?? 0;
        $p1 = $_GET['p1'] ?? 1;
        $n2 = $_GET['n2'] ?? 0;
        $p2 = $_GET['p2'] ?? 1;
    ?>

    <main>
        <h1>Médias Aritméticas</h1>
        <form action="<?=$_SERVER['PHP_SELF']?>" method="get">
            <label for="n1">1ª Nota</label>
            <input type="number" name="n1" id="n1" value="<?=$n1?>" step="0.01">
            <label for="p1">1º Peso</label>
            <input type="number" name="p1" id="p1" value="<?=$p1?>">
            <label for="n2">2ª Nota</label>
            <input type="number" name="n2" id="n2" value="<?=$n2?>" step="0.01">
            <label for="p2">2º Peso</label>
            <input type="number" name="p2" id="p2" value="<?=$p2?>">
            <input type="submit" value="Calcular Médias">
        </form>
    </main>

    <section id="resultado">
        <h2>Cálculo das Médias</h2>
        <?php 
            $mSimples = ($n1 + $n2)/2;
            $mPonderada = (($n1*$p1) + ($n2*$p2))/ ($p1+$p2);
            echo "<p>Analisando as notas <strong>$n1</strong> e <strong>$n2</strong>, temos:
            <ul>
            <li>A <strong>Média Aritmética Simples</strong> entre as notas $n1 e $n2 é igual a <strong>". number_format((float) $mSimples, 2, ",", ""). "</strong>.</li>
            <li>Já a <strong>Média Aritmética Ponderada</strong> com pesos $p1 e $p2 é igual a <strong>". number_format((float) $mPonderada, 2, ",", ""). "</strong></li>
            </ul> 
            </p>";
        ?>
        
    </section>
</body>
</html>