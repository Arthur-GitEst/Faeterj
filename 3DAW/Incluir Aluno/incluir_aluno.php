<?php
  if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $mat = $_POST["mat"];
    $nome = $_POST["nome"];
    $email = $_POST["email"];

    if(!file_exists("disciplinas.txt")) {
      $arqAluno = fopen("disciplinas.txt", "w") or die("Não foi possível criar o arquivo.");
    }

    $arqAluno = fopen("alunos.txt", "a") or die("Não foi possível abrir o arquivo.");
    fwrite($arqAluno, $mat . ";" . $nome . ";" . $email);
    fclose($arqAluno);
    $msg = "Aluno incluído com sucesso!";
  }
?>

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Disciplinas</title>
</head>
<body>
  <h1>Incluir Aluno</h1>

  <form method="POST" action="incluir_aluno.php">
    <label for="mat">Matrícula:</label>
    <input type="text" id="mat" name="mat" required><br><br>

    <label for="nome">Nome:</label>
    <input type="text" id="nome" name="nome" required><br><br>

    <label for="email">E-mail:</label>
    <input type="email" id="email" name="email" required><br><br>

    <input type="submit" value="Incluir Aluno">
  </form>

  <h1>Alunos Cadastrados</h1>
  <ul>
    <?php
      if (file_exists("alunos.txt")) {
        $arqAluno = fopen("alunos.txt", "r") or die("Não foi possível abrir o arquivo.");
        while (!feof($arqAluno)) {
          $linha = fgets($arqAluno);
          if (!empty($linha)) {
            list($mat, $nome, $email) = explode(";", $linha);
            echo "<li>$mat - $nome - $email</li>";
          }
        }
        fclose($arqAluno);
      }
    ?>
  </ul>
</body>
</html>