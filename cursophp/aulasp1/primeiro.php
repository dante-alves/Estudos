<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    
    <?php 
       $nota1 = $_GET ['nota1'] ?? 0;
       $nota2 = $_GET ['nota2'] ?? 0;
       $nota3 = $_GET ['nota3'] ?? 0;
    ?>

    <form action="<?=$_SERVER['PHP_SELF']?>" method="get">
        <p>
            <label for="nota1">Nota 1</label>
            <input type="number" name="nota1" id="inota1" value="<?=$nota1?> " max="10" min="0" step="0.01">
            <label for="nota2">Nota 2</label>
            <input type="number" name="nota2" id="inota2" value="<?=$nota2?>" max="10" min="0" step="0.01">
            <label for="nota3">Nota 3</label>
            <input type="number" name="nota3" id="inota3" value="<?=$nota3?>" max="10" min="0" step="0.01">
        </p>
        <p>
        </p>
        <p>
            <input type="submit" value="Enviar">
            <input type="reset" value="Limpar">
        </p>
    </form>
    <?php 
        $media = ($nota1 + $nota2 + $nota3)/3;

        echo "A média entre as notas $nota1, $nota2 e $nota3 é igual a ". number_format($media, 2, ",");
    ?>
</body>
</html>