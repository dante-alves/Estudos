<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Caixa Eletrônico</title>
    <link rel="stylesheet" href="style.css">
    <style>
        img.money {
            height: 40px;
            margin: 3px;
        }
        h1 {
            color: rgb(35, 2, 222);
            text-shadow: 1px 1px 1px black;
            text-align: center;
        }
    </style>
</head>
<body>
    <?php 
        $total = $_GET['total'] ?? 0;
    ?>

    <main>
        <h1>Caixa Eletrônico</h1>
        <form action="<?=$_SERVER['PHP_SELF']?>" method="$_GET">
            <label for="total">Qual valor você deseja sacar? (R$)<sup>*</sup></label>
            <input type="number" name="total" id="total" value="<?=$total?>">
            <input type="submit" value="Sacar">
        </form>
    </main>

    <section>      
        <?php 
            $sobra = $total;
            $cem = intdiv($sobra, 100);
            $sobra = $sobra % 100;

            $cinquenta = intdiv($sobra, 50);
            $sobra = $sobra % 50;

            $vinte = intdiv($sobra, 20);
            $sobra = $sobra % 20;

            $dez = intdiv($sobra, 10);
            $sobra = $sobra % 10;
            
            $cinco = intdiv($sobra, 5);
            $sobra = $sobra % 5;
           
            $dois = intdiv($sobra, 2);
            $sobra = $sobra % 2;
            
            $um = $sobra;
        ?>
        
        <h2>Saque de R$<?=$total?> realizado</h2>
        <p>O caixa eletrônico vai te entregar as seguintes notas:</p> 
            <ul>
                <li><img src="imagens/100-reais.jpg" alt="cem" class="money"> X <?=$cem?></li>
                <li><img src="imagens/50-reais.jpg" alt="cinquenta" class="money"> X <?=$cinquenta?></li>
                <li><img src="imagens/20-reais.jpg" alt="vinte" class="money"> X <?=$vinte?></li>
                <li><img src="imagens/10-reais.jpg" alt="dez" class="money"> X <?=$dez?></li>
                <li><img src="imagens/5-reais.jpg" alt="cinco" class="money"> X <?=$cinco?></li>
                <li><img src="imagens/2-reais.jpg" alt="dois" class="money"> X <?=$dois?></li>
                <li><img src="imagens/1-real.jpg" alt="um" class="money"> X <?=$um?></li>
                </ul>
    </section>
</body>
</html>