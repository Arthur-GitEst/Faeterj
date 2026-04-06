<?php
  if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $sigla = $_POST["sigla"];
    $nome = $_POST["nome"];
    $carga = $_POST["carga"];

    if(!file_exists("disciplinas.txt")) {
      $arqDisciplina = fopen("disciplinas.txt", "w") or die("Não foi possível criar o arquivo.");
    }

    $arqDisciplina = fopen("disciplinas.txt", "a") or die("Não foi possível abrir o arquivo.");
    fwrite($arqDisciplina, $sigla . ";" . $nome . ";" . $carga . "\n");
    fclose($arqDisciplina);
    $msg = "Disciplina incluída com sucesso!";
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
  <h1>Incluir Disciplina</h1>

  <form method="POST" action="incluir_disciplina.php">
    <label for="sigla">Sigla:</label>
    <input type="text" id="sigla" name="sigla" required><br><br>

    <label for="nome">Nome:</label>
    <input type="text" id="nome" name="nome" required><br><br>

    <label for="carga">Carga Horária:</label>
    <input type="number" id="carga" name="carga" required><br><br>

    <input type="submit" value="Incluir Disciplina">
  </form>

  <h1>Disciplinas Cadastradas</h1>
  <ul>
    <?php
      if (file_exists("disciplinas.txt")) {
        $arqDisciplina = fopen("disciplinas.txt", "r") or die("Não foi possível abrir o arquivo.");
        while (!feof($arqDisciplina)) {
          $linha = fgets($arqDisciplina);
          if (!empty($linha)) {
            list($sigla, $nome, $carga) = explode(";", $linha);
            echo "<li>$sigla - $nome - $carga horas</li>";
          }
        }
        fclose($arqDisciplina);
      }
    ?>
  </ul>
</body>
</html>