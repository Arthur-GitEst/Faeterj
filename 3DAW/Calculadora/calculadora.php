<?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $n1 = $_POST["a"];
        $n2 = $_POST["b"];
        $multiplicacao = $n1 * $n2;
    }
?>
<!DOCTYPE html>
<html>
<body>
<h1><?php echo 'Calculadora de Multiplicação'; ?></h1>

<form method='POST' action='calculadora.php'>
    N1:<input type=text name='a'><br>
    N2:<input type=text name='b'><br><br>
    <input type=submit value='Multiplicar'>
    <br><br>
    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        echo 'Resultado: ' . $multiplicacao;
    }
    ?>
</form>
</body>
</html>
