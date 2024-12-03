<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Enviar Email</title>
    <style>
        * {
            font-family: Arial, Helvetica, sans-serif;
        }
        .msg {
            display: block;
            border: 1px solid black;
            margin: 10px 0px;
            padding: 5px 5px 100px 5px;
            width: 700px;

        }

        textarea {
            display: block;
            resize: none;
        }

        a {
            text-decoration: none;
            color: black;
            border: 1px solid black;
            background-color: white;
            padding: 5px;
        }

        a:hover {
            background-color: rgb(216, 216, 216);
            cursor: pointer;
        }
    </style>
</head>
<body>
    <h1>Confira os dados</h1>
    <?php 
        $nome = $_POST['nome'] ?? '';
        $email = $_POST['email'] ?? '';
        $assunto = $_POST['assunto'] ?? '';
        $mensagem = $_POST['mensagem'] ?? '';
 
        echo ' 
        <p>Nome: '. $nome. '</p>
        <p>Email: '. $email. '</p>
        <p>Assunto: '. $assunto. ' </p>
        <p>Mensagem: <span class="msg"> '. $mensagem. '</span></p>    
        <a href="mailto:'. $email. '?subject='. $assunto. '&body='. $mensagem. " Ass: $nome". '">Enviar?</a>
        <a onclick="history.back()">Voltar</a>'
    ?>
</body>
</html>