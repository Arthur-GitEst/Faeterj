<?php
  $arqPerguntas = "perguntas.txt";
  $msg = "";
  $indiceSelecionado = $_POST["indice"] ?? "";
  $mostrarEdicao = false;
  $registroAtual = [];

  $linhas = [];
  if (file_exists($arqPerguntas)) {
    $linhas = file($arqPerguntas, FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);
  }

  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $acao = $_POST["acao"];

    if (!file_exists($arqPerguntas)) {
      $msg = "Arquivo de perguntas não encontrado.";
    } elseif (count($linhas) === 0) {
      $msg = "Nenhuma pergunta cadastrada.";
    } elseif ($indiceSelecionado === "") {
      $msg = "Selecione uma pergunta válida.";
    } else {
      $partes = explode(";", $linhas[$indiceSelecionado]);
      $tipo = trim($partes[0]);

      if ($tipo === "multipla" && count($partes) >= 4) {
        $registroAtual = [
          "tipo" => "multipla",
          "pergunta" => trim($partes[1]),
          "resposta" => trim($partes[3]),
          "partes" => $partes,
        ];
      } elseif ($tipo === "discursiva" && count($partes) >= 3) {
        $registroAtual = [
          "tipo" => "discursiva",
          "pergunta" => trim($partes[1]),
          "resposta" => trim($partes[2]),
          "partes" => $partes,
        ];
      } else {
        $msg = "Registro inválido para alteração.";
      }

      if ($msg === "") {
        if ($acao === "carregar") {
          $mostrarEdicao = true;
        } elseif ($acao === "salvar") {
          $novaPergunta = trim($_POST["pergunta"]);
          $novaResposta = trim($_POST["resposta"]);

          if ($novaPergunta === "" || $novaResposta === "") {
            $msg = "Preencha pergunta e resposta para salvar.";
            if ($novaPergunta !== "") {
              $registroAtual["pergunta"] = $novaPergunta;
            }
            if ($novaResposta !== "") {
              $registroAtual["resposta"] = $novaResposta;
            }
            $mostrarEdicao = true;
          } else {
            $partes = $registroAtual["partes"];
            $partes[1] = $novaPergunta;
            if ($registroAtual["tipo"] === "multipla") {
              $partes[3] = $novaResposta;
            } else {
              $partes[2] = $novaResposta;
            }

            $linhas[$indiceSelecionado] = implode(";", $partes);
            file_put_contents($arqPerguntas, implode(PHP_EOL, $linhas) . PHP_EOL);

            $msg = "Pergunta alterada com sucesso!";
            $registroAtual["pergunta"] = $novaPergunta;
            $registroAtual["resposta"] = $novaResposta;
            $registroAtual["partes"] = $partes;
            $mostrarEdicao = true;
          }
        }
      }
    }

    if ($msg !== "") {
      echo "<script>alert('" . $msg . "');</script>";
    }
  }
?>

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Aplicação Web - Alterar Pergunta</title>
</head>
<body>
  <p>
    <a href="adicionar.php">Adicionar Perguntas</a> |
    <a href="listar.php">Listar Perguntas</a> |
    <a href="listar_especifica.php">Listar Pergunta Específica</a> |
    <a href="alterar.php">Alterar Pergunta</a> |
    <a href="excluir.php">Excluir Pergunta</a>
  </p>

  <h1>Alterar Pergunta</h1>

  <?php if (!file_exists($arqPerguntas)): ?>
    <p>Arquivo de perguntas não encontrado.</p>
  <?php elseif (count($linhas) === 0): ?>
    <p>Nenhuma pergunta cadastrada.</p>
  <?php else: ?>
    <form action="alterar.php" method="post">
      <label for="indice">Selecione a pergunta:</label>
      <select id="indice" name="indice" required>
        <?php foreach ($linhas as $indice => $linha): ?>
          <?php
            $partes = explode(";", $linha);
            $tipo = trim($partes[0]);
            $textoPergunta = trim($partes[1]);
          ?>
          <option value="<?php echo $indice; ?>" <?php echo $indiceSelecionado == $indice ? "selected" : ""; ?>>
            <?php echo ($indice + 1) . " - " . $tipo . " - " . $textoPergunta; ?>
          </option>
        <?php endforeach; ?>
      </select>
      <button type="submit" name="acao" value="carregar">Carregar</button>
    </form>

    <?php if ($mostrarEdicao): ?>
      <h2>Editar</h2>
      <form action="alterar.php" method="post">
        <input type="hidden" name="indice" value="<?php echo $indiceSelecionado; ?>">

        <p>Tipo: <?php echo $registroAtual["tipo"]; ?></p>

        <label for="pergunta">Pergunta:</label><br>
        <input type="text" id="pergunta" name="pergunta" value="<?php echo $registroAtual["pergunta"]; ?>" required><br><br>

        <label for="resposta">Resposta:</label><br>
        <input type="text" id="resposta" name="resposta" value="<?php echo $registroAtual["resposta"]; ?>" required><br><br>

        <button type="submit" name="acao" value="salvar">Salvar Alteração</button>
      </form>
    <?php endif; ?>
  <?php endif; ?>
</body>
</html>
