<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Cadastro de Usuário</title>
    <style>
        label {
            display: block;
        }
    </style>
</head>
<body>
    
    <?php 
       $nome = $_GET ['nome'] ?? '';
       $senha = $_GET ['senha'] ?? '';
       $email = $_GET ['email'] ?? '';
    ?>

    <form action="<?=$_SERVER['PHP_SELF']?>" method="get">
        <h1>Cadastro de Usuário</h1>
        <p>
            <label for="nome">Nome</label>
            <input type="text" name="nome" id="inome" autocomplete="off" required placeholder="Nome completo">
            <label for="senha">Senha</label>
            <input type="password" name="senha" id="isenha" autocomplete="off" required minlength="8" maxlength="15" placeholder="Insira sua senha">
            <label for="email">Email</label>
            <input type="email" name="email" id="iemail" autocomplete="off" required placeholder="Insira seu melhor email">

        </p>
        <p>
        </p>
        <p>
            <input type="submit" value="Cadastrar">
            <input type="reset" value="Limpar">
        </p>
    </form>

    <?php 
        echo "<p>Cadastro realizado com sucesso! É um prazer, $nome. Sua senha é $senha e uma confirmação foi enviada para o email $email.</p>"
    ?>
</body>
</html>