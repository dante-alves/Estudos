<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>To-Do-List</title>
    <style>
        body {
            text-align: center;
        }
        label {
            display: block;
        }
    
    </style>
</head>
<body>
    
    <?php 
        //Iniciar sessão
        session_start();

        if(!isset($_SESSION['lista'])) {
            $_SESSION['lista'] = [];
        }

        $tarefa = trim($_POST ['tarefa']) ?? '';

        if(!empty($tarefa) && !in_array($tarefa ,$_SESSION['lista'])) {
            $_SESSION['lista'][] = $tarefa;
        } 

        $lista = $_SESSION['lista'];

        //Limpar as tarefas
        if (isset($_POST['limpar'])) {
            $_SESSION['lista'] = [];
        }
    ?>

    <form action="<?=$_SERVER['PHP_SELF']?>" method="post">
        <h1>To-Do-List</h1>
        <p>
            <label for="tarefa">Tarefa</label>
            <input type="text" name="tarefa" autocomplete="off" placeholder="Adicionar Tarefa..." <? isset($_POST['limpar']) ? '' : 'required'?>
        </p>
        <p>
            <input type="submit" value="Adicionar">
            <input type="submit" value="Limpar" name="limpar">
        </p>
    </form>

    <?php 
        echo "<h2> Lista de Tarefas: </h2>";
        if(!empty($lista)) {
            foreach($lista as $tarefa) {
                echo "<p><input type=\"checkbox\">$tarefa</p>";
            }
        }

    ?>
</body>
</html>