<?php
  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $pergunta = trim($_POST["pergunta"]);
    $falsas = $_POST["falsas"];
    $correta = trim($_POST["correta"]);

    if (!file_exists("perguntas.txt")) {
      $arqPerguntas = fopen("perguntas.txt", "a") or die ("Não foi possível criar o arquivo.");
    }

    $arqPerguntas = fopen("perguntas.txt", "a") or die ("Não foi possível abrir o arquivo.");
    if(filesize("perguntas.txt") > 0) {
      fwrite($arqPerguntas, "\n");
    }
    fwrite($arqPerguntas, "Pergunta:$pergunta;Alternativas Falsas:" . implode(",", $falsas) . ";Resposta Correta:$correta\n");
    fclose($arqPerguntas);
    $msg = "Pergunta e respostas salvas com sucesso!";
    echo "<script>alert('$msg');</script>";
  }
?>

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Aplicação Web</title>
</head>
<body>
  <h1>Criar Perguntas de Múltipla Escolha</h1>

  <form action="aplicacao.php" method="post">
    <label for="pergunta">Pergunta:</label><br>
    <input type="text" id="pergunta" name="pergunta" required><br><br>

    <label for="falsa">Alternativas Falsas:</label><br>
    <input type="text" id="falsa1" name="falsas[]" required><br>
    <input type="text" id="falsa2" name="falsas[]" required><br>
    <input type="text" id="falsa3" name="falsas[]" required><br>

    <label for="correta">Resposta:</label><br>
    <input type="text" id="correta" name="correta" required><br><br>

    <input type="submit" value="Enviar">
  </form>
</body>
</html>