<?php
	$arqPerguntas = "perguntas.txt";
	$indiceSelecionado = $_POST["indice"] ?? "";

	$linhas = [];
	if (file_exists($arqPerguntas)) {
		$linhas = file($arqPerguntas, FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);
	}

	if ($_SERVER["REQUEST_METHOD"] == "POST") {
		if (!file_exists($arqPerguntas)) {
			$msg = "Arquivo de perguntas não encontrado.";
		} elseif (count($linhas) === 0) {
			$msg = "Nenhuma pergunta cadastrada.";
		} else {
			unset($linhas[$indiceSelecionado]);
			$linhas = array_values($linhas);

			if (count($linhas) > 0) {
				file_put_contents($arqPerguntas, implode(PHP_EOL, $linhas) . PHP_EOL);
			} else {
				file_put_contents($arqPerguntas, "");
			}

			$msg = "Pergunta excluída com sucesso!";
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
	<title>Aplicação Web - Excluir Pergunta</title>
</head>
<body>
	<p>
		<a href="adicionar.php">Adicionar Perguntas</a> |
		<a href="listar.php">Listar Perguntas</a> |
		<a href="listar_especifica.php">Listar Pergunta Específica</a> |
		<a href="alterar.php">Alterar Pergunta</a> |
		<a href="excluir.php">Excluir Pergunta</a>
	</p>

	<h1>Excluir Pergunta</h1>

	<?php if (!file_exists($arqPerguntas)): ?>
		<p>Arquivo de perguntas não encontrado.</p>
	<?php elseif (count($linhas) === 0): ?>
		<p>Nenhuma pergunta cadastrada.</p>
	<?php else: ?>
		<form action="excluir.php" method="post">
			<label for="indice">Selecione a pergunta:</label>
			<select id="indice" name="indice" required>
				<?php foreach ($linhas as $indice => $linha): ?>
					<?php
						$partes = explode(";", $linha);
						$tipo = trim($partes[0] ?? "registro incorreto");
						$textoPergunta = trim($partes[1] ?? "");
					?>
					<option value="<?php echo $indice; ?>" <?php echo $indiceSelecionado == $indice ? "selected" : ""; ?>>
						<?php echo ($indice + 1) . " - " . $tipo . " - " . $textoPergunta; ?>
					</option>
				<?php endforeach; ?>
			</select>

			<button type="submit">Excluir</button>
		</form>
	<?php endif; ?>
</body>
</html>
