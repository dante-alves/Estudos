<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Exercício 3</title>
    <style>
        body {
            text-align: center;
        }

        img {
            width: 200px;
        }
    </style>
</head>
<body>
    <h1>Área do trapézio</h1>
    <form method="POST">
        <p>
            <label for="bMaior">Insira a base maior</label>
            <input type="number" name="bMaior" step="0.01" required placeholder="Em metros">
      
        </p>
        <p>
            <label for="bMenor">Insira a base menor</label>
            <input type="number" name="bMenor" step="0.01" required placeholder="Em metros">
      
        </p>
        <p>
            <label for="altura">Insira a altura</label>
            <input type="number" name="altura" step="0.01" required placeholder="Em metros">
        </p>

        <p>
            <input type="submit" value="Calcular a área">
        </p>
    </form>
    <?php 
        if ($_SERVER["REQUEST_METHOD"] == "POST") {
            $bMaior = $_POST['bMaior'] ?? 0;
            $bMenor = $_POST['bMenor'] ?? 0;
            $altura = $_POST['altura'] ?? 0;

            $area = ($bMaior + $bMenor) / 2 * $altura;
            echo "O trapézio tem uma área de $area m²<br>";
        }
    ?>
    <img src="https://matematicabasica.net/wp-content/uploads/2019/02/trapezio-8.png" alt="Trapezio">
</body>
</html>

