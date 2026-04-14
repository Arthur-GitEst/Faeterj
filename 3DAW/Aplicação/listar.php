<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Aplicação Web - Listar Perguntas</title>
</head>
<body>
  <p>
    <a href="adicionar.php">Adicionar Perguntas</a> |
    <a href="listar.php">Listar Perguntas</a> |
    <a href="listar_especifica.php">Listar Pergunta Específica</a> |
    <a href="alterar.php">Alterar Pergunta</a> |
    <a href="excluir.php">Excluir Pergunta</a>
  </p>

  <h1>Listar Perguntas</h1>

  <?php
    $arqPerguntas = "perguntas.txt";
    if (!file_exists($arqPerguntas)) {
      echo "<p>Arquivo de perguntas não encontrado.</p>";
    } else {
      $perguntas = file($arqPerguntas, FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);

      if (count($perguntas) === 0) {
        echo "<p>Nenhuma pergunta cadastrada.</p>";
      } else {
        echo "<ul>";

        foreach ($perguntas as $linha) {
          $partes = explode(";", $linha);
          $tipo = trim($partes[0]);

          echo "<li>";

          if ($tipo === "multipla" && count($partes) >= 4) {
            $pergunta = trim($partes[1]);
            $alternativasFalsas = trim($partes[2]);
            $respostaCorreta = trim($partes[3]);

            echo "<strong>Tipo:</strong> multipla<br>";
            echo "<strong>Pergunta:</strong> $pergunta<br>";
            echo "<strong>Alternativas Falsas:</strong> $alternativasFalsas<br>";
            echo "<strong>Resposta Correta:</strong> $respostaCorreta";
          } elseif ($tipo === "discursiva" && count($partes) >= 3) {
            $pergunta = trim($partes[1]);
            $resposta = trim($partes[2]);

            echo "<strong>Tipo:</strong> discursiva<br>";
            echo "<strong>Pergunta:</strong> $pergunta<br>";
            echo "<strong>Resposta:</strong> $resposta";
          } else {
            echo "<strong>Registro inválido:</strong> $linha";
          }

          echo "</li><br>";
        }

        echo "</ul>";
      }
    }
  ?>
</body>
</html>