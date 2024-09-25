<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Contador de visistas na página</title>
</head>
<body>
    <h1>Contador de visistas</h1>
    <?php
// Caminho para o arquivo que armazena o contador
$contador_arquivo = 'contador.txt';

// Verifica se o arquivo existe
if (file_exists($contador_arquivo)) {
    // Lê o valor atual do contador
    $contador = file_get_contents($contador_arquivo);
    // Verifica se o valor lido é um número inteiro
    if (is_numeric($contador)) {
        // Incrementa o contador
        $contador++;
    } else {
        // Se não for um número válido, começa do zero
        $contador = 1;
    }
} else {
    // Se o arquivo não existir, começa do zero
    $contador = 1;
}

// Atualiza o arquivo com o novo valor do contador
file_put_contents($contador_arquivo, $contador);

// Exibe o número de visitas
echo "Número de visitas: " . $contador;
?>
</body>
</html>
