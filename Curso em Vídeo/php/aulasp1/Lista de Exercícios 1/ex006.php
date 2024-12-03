<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Cadastro de Usuário</title>
    <style>
        
        body {
            text-align: center;
        }
        
        label {
            display: block;
        }
        
        input {
            margin-bottom: 10px;
        }

        mark {
            background-color: white;
            color: red;
        }
    </style>
</head>
<body>
    
    <?php 
       $nome = $_POST ['nome'] ?? '';
       $senha = $_POST ['senha'] ?? '';
    ?>

    <form action="<?=$_SERVER['PHP_SELF']?>" method="post">
        <h1>Login</h1>
        <?php 
            if ($nome == 'Dante Alves e Silva' && $senha == 'Pastel123')
                echo "<h2>Bem vindo, $nome!</h2>";
            else {
                echo '
            <p><mark>Nome ou senha inválidos, insira os dados novamente.</mark></p>
            <p>
            <label for="nome">Nome</label>
            <input type="text" name="nome" id="inome" autocomplete="off" required placeholder="Nome completo">
            <label for="senha">Senha</label>
            <input type="password" name="senha" id="isenha" autocomplete="off" required minlength="8" maxlength="15" placeholder="Insira sua senha">
        </p>
        <p>
            <input type="submit" value="Login">
            <input type="reset" value="Limpar">
        </p>';
            }
        ?>
    </form>
</body>
</html>