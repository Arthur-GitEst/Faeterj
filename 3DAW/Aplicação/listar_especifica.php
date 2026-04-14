<?php
  $arqPerguntas = "perguntas.txt";
  $busca = trim($_GET["pergunta"] ?? "");
  $buscou = isset($_GET["pergunta"]);
  $resultados = [];

  if ($busca !== "" && file_exists($arqPerguntas)) {
    $linhas = file($arqPerguntas, FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);

    foreach ($linhas as $linha) {
      $partes = explode(";", $linha);
      $tipo = trim($partes[0] ?? "");

      if ($tipo === "multipla" && count($partes) >= 4) {
        $pergunta = trim($partes[1]);
        $resposta = trim($partes[3]);
      } elseif ($tipo === "discursiva" && count($partes) >= 3) {
        $pergunta = trim($partes[1]);
        $resposta = trim($partes[2]);
      } else {
        continue;
      }

      if ($pergunta === $busca) {
        $resultados[] = [
          "tipo" => $tipo,
          "pergunta" => $pergunta,
          "resposta" => $resposta,
        ];
      }
    }
  }
?>

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Aplicação Web - Listar Pergunta Específica</title>
</head>
<body>
  <p>
    <a href="adicionar.php">Adicionar Perguntas</a> |
    <a href="listar.php">Listar Perguntas</a> |
    <a href="listar_especifica.php">Listar Pergunta Específica</a> |
    <a href="alterar.php">Alterar Pergunta</a> |
    <a href="excluir.php">Excluir Pergunta</a>
  </p>

  <h1>Listar Pergunta Específica</h1>

  <form action="listar_especifica.php" method="get">
    <label for="pergunta">Digite a pergunta a ser buscada:</label>
    <input type="text" id="pergunta" name="pergunta" required>
    <button type="submit">Buscar</button>
  </form>

  <?php if (!file_exists($arqPerguntas)): ?>
    <p>Arquivo de perguntas não encontrado.</p>
  <?php elseif ($buscou && $busca === ""): ?>
    <p>Digite uma pergunta para buscar.</p>
  <?php elseif ($busca !== "" && count($resultados) === 0): ?>
    <p>Pergunta não encontrada.</p>
  <?php elseif (count($resultados) > 0): ?>
    <h2>Resultado da Busca</h2>
    <ul>
      <?php foreach ($resultados as $item): ?>
        <li>
          <strong>Tipo:</strong> <?php echo $item["tipo"]; ?><br>
          <strong>Pergunta:</strong> <?php echo $item["pergunta"]; ?><br>
          <strong>Resposta:</strong> <?php echo $item["resposta"]; ?>
        </li>
        <br>
      <?php endforeach; ?>
    </ul>
  <?php endif; ?>
</body>
</html>