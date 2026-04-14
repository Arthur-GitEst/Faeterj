<?php
  $tipoSelecionado = "multipla";
  $msg = "";

  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $tipoSelecionado = $_POST["tipo"] ?? "multipla";
    if ($tipoSelecionado !== "multipla" && $tipoSelecionado !== "discursiva") {
      $tipoSelecionado = "multipla";
    }

    $acao = $_POST["acao"] ?? "atualizar";

    if ($acao === "salvar") {
      $pergunta = trim($_POST["pergunta"] ?? "");
      $resposta = trim($_POST["resposta"] ?? "");
      $gravacao = "";

      if ($tipoSelecionado === "discursiva") {
        if ($pergunta !== "" && $resposta !== "") {
          $gravacao = "discursiva;$pergunta;$resposta";
        }
      } else {
        $falsas = $_POST["falsas"] ?? [];
        $falsas = array_filter(array_map("trim", $falsas), function ($valor) {
          return $valor !== "";
        });

        if ($pergunta !== "" && count($falsas) === 3 && $resposta !== "") {
          $gravacao = "multipla;$pergunta;" . implode(",", $falsas) . ";$resposta";
        }
      }

      if ($gravacao !== "") {
        file_put_contents("perguntas.txt", $gravacao . PHP_EOL, FILE_APPEND);
        $msg = "Pergunta salva com sucesso!";
      } else {
        $msg = "Preencha todos os campos obrigatórios para o tipo selecionado.";
      }
      echo "<script>alert('" . $msg . "');</script>";
    }
  }
?>

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Aplicação Web - Adiciona Pergunta</title>
</head>
<body>
  <p>
    <a href="adicionar.php">Adicionar Perguntas</a> |
    <a href="listar.php">Listar Perguntas</a> |
    <a href="listar_especifica.php">Listar Pergunta Específica</a> |
    <a href="alterar.php">Alterar Pergunta</a> |
    <a href="excluir.php">Excluir Pergunta</a>
  </p>

  <div style="display: flex; flex-direction: column; justify-content: center; align-items: center; gap: 2rem">
  <h1>Criar Perguntas</h1>

  <form action="adicionar.php" method="post">
    <label for="tipo">Tipo de pergunta:</label><br>
    <select id="tipo" name="tipo">
      <option value="multipla" <?php echo $tipoSelecionado === "multipla" ? "selected" : ""; ?>>Múltipla escolha</option>
      <option value="discursiva" <?php echo $tipoSelecionado === "discursiva" ? "selected" : ""; ?>>Discursiva</option>
    </select><br><br>

    <button type="submit" name="acao" value="atualizar" formnovalidate>Selecionar tipo</button>

    <br><br>

    <label for="pergunta">Pergunta:</label><br>
    <input type="text" id="pergunta" name="pergunta" required><br><br>

    <?php if ($tipoSelecionado === "multipla"): ?>
      <label for="falsa1">Alternativas Falsas:</label><br>
      <input type="text" id="falsa1" name="falsas[]" required><br>
      <input type="text" id="falsa2" name="falsas[]" required><br>
      <input type="text" id="falsa3" name="falsas[]" required><br><br>

      <label for="resposta-multipla">Resposta Correta:</label><br>
      <input type="text" id="resposta-multipla" name="resposta" required><br><br>
    <?php else: ?>
      <label for="resposta-discursiva">Resposta esperada:</label><br>
      <input type="text" id="resposta-discursiva" name="resposta" required><br><br>
    <?php endif; ?>

    <button type="submit" name="acao" value="salvar">Enviar</button>
  </form>
  </div>
</body>
</html>