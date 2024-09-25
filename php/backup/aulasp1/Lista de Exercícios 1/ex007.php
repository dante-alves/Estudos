<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Randomizer</title>
    <style>
        label {
            display: block;
        }

        #container input[type="submit"] {
            background-color: red;
            color: white;
            font-weight: bolder;
        }

        #container input[type="submit"]:hover {
            cursor: pointer;
        }

        #container {
            position: absolute;

            top: 50%;
            left: 50%;

            transform: translate(-50%, -50%);
        }

        #gerado {
            text-align: center;
            margin: auto;
        }
    </style>
</head>
<body>

    <form action="<?=$_SERVER['PHP_SELF']?>" method="get" id="container"> 
        <h1>Randomizer</h1>

        <p>
            <input type="submit" value="Gerar número aleatório">
        </p>
    <?php 
        $min = 0;
        $max = 1000;
        $num = mt_rand($min, $max);
        echo "<p id=\"gerado\">Número gerado: $num</p>";
    ?>
    </form>

</body>
</html>