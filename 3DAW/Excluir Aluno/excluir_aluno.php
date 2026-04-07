<?php
  if ($_SERVER['REQUEST_METHOD'] == 'POST' && isset($_POST["mat"], $_POST["nome"], $_POST["email"])) {
    $mat = trim($_POST["mat"]);
    $nome = trim($_POST["nome"]);
    $email = trim($_POST["email"]);

    if (!file_exists("alunos.txt")) {
      $arqAluno = fopen("alunos.txt", "w") or die("Não foi possível criar o arquivo.");
      fclose($arqAluno);
    }

    $arqAluno = fopen("alunos.txt", "a") or die("Não foi possível abrir o arquivo.");
    if (filesize("alunos.txt") > 0) {
      fwrite($arqAluno, "\n");
    }
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

  <form method="POST" action="excluir_aluno.php">
    <label for="mat">Matrícula:</label>
    <input type="text" id="mat" name="mat" required><br><br>

    <label for="nome">Nome:</label>
    <input type="text" id="nome" name="nome" required><br><br>

    <label for="email">E-mail:</label>
    <input type="email" id="email" name="email" required><br><br>

    <input type="submit" value="Incluir Aluno">
  </form>

  <h1>Excluir Aluno</h1>

  <?php
    if ($_SERVER['REQUEST_METHOD'] == 'POST' && isset($_POST["matExcluir"])) {
      $matExcluir = trim($_POST["matExcluir"]);
      $alunos = [];
      $encontrouMatricula = false;

      if (file_exists("alunos.txt")) {
        $arqAluno = fopen("alunos.txt", "r") or die("Não foi possível abrir o arquivo.");
        while (!feof($arqAluno)) {
          $linha = fgets($arqAluno);
          $linha = trim($linha);
          if (!empty($linha)) {
            $dados = explode(";", $linha);
            if (count($dados) < 3) {
              continue;
            }

            list($mat, $nome, $email) = $dados;
            if ($mat !== $matExcluir) {
              $alunos[] = "$mat;$nome;$email";
            } else {
              $encontrouMatricula = true;
            }
          }
        }
        fclose($arqAluno);

        $arqAluno = fopen("alunos.txt", "w") or die("Não foi possível abrir o arquivo.");
        if (!empty($alunos)) {
          fwrite($arqAluno, implode("\n", $alunos));
        }
        fclose($arqAluno);

        if ($encontrouMatricula) {
          echo "<p>Aluno com matrícula $matExcluir excluído com sucesso!</p>";
        } else {
          echo "<p>Matrícula não encontrada até o final do arquivo.</p>";
        }
      } else {
        echo "<p>Arquivo de alunos não encontrado.</p>";
      }
    }
  ?>

  <form method="POST" action="excluir_aluno.php">
    <label for="matExcluir">Matrícula do Aluno a Excluir:</label>
    <input type="text" id="matExcluir" name="matExcluir" required><br><br>

    <input type="submit" value="Excluir Aluno">
  </form>

  <h1>Alunos Cadastrados</h1>
  <ul>
    <?php
      if (file_exists("alunos.txt")) {
        $arqAluno = fopen("alunos.txt", "r") or die("Não foi possível abrir o arquivo.");
        while (!feof($arqAluno)) {
          $linha = fgets($arqAluno);
          $linha = trim($linha);
          if (!empty($linha)) {
            $dados = explode(";", $linha);
            if (count($dados) < 3) {
              continue;
            }

            list($mat, $nome, $email) = $dados;
            echo "<li>$mat - $nome - $email</li>";
          }
        }
        fclose($arqAluno);
      }
    ?>
  </ul>
</body>
</html>