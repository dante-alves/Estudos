<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Media</title>
    <style>
        body {
            text-align: center;
        }

        input.notas {
            width: 10.8vw;
        }
    </style>
</head>
<body>
    <h1>RESULTADO:</h1>
    <?php
        // chamar a funcao
       function calculoMedia($nota1, $nota2)
       {
            $media = ($nota1 + $nota2)/2;
            return "<p>A media é <strong> " . number_format($media, 2) . "</strong></p>";
       }
       // chamar a funcao
       echo calculoMedia($nota1 = $_POST['nota1'] ?? 0, $nota2 = $_POST['nota2'] ?? 0);
    ?>
</body>
</html>