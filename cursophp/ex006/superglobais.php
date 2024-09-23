<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Superglobais</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <section>
        <pre>
            <?php
                setcookie("dia-da-semana", "SEGUNDA", time() + 3600);

                session_start();
                $_SESSION["teste"] = "FUNCIONOU";
                
                echo '<h1>Superglobal $_GET </h1>';
                var_dump($_GET);
                
                echo'<h1>Superglobal $_POST </h1>';
                var_dump($_POST);
                
                echo'<h1>Superglobal $_REQUEST</h1>';
                var_dump($_REQUEST);
                
                echo'<h1>Superglobal $_COOKIE</h1>';
                var_dump($_COOKIE);

                echo'<h1>Superglobal $_SESSION</h1>';
                var_dump($_SESSION);
                echo'<h1>Superglobal $_ENV</h1>';
                var_dump($_ENV);
                /*foreach (getenv() as $c => $v) {
                    echo "<br> $c -> $v <br>"; 
                }*/

                echo'<h1>Superglobal $_SERVER</h1>';
                var_dump($_SERVER);

                echo'<h1>Superglobal $GLOBALS</h1>';
                var_dump($GLOBALS);
            ?>
        </pre>
    </section>
</body>
</html>