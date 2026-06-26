<?php

header('Content-Type: application/json; charset=utf-8');

$dbPath = __DIR__ . '/../salon.db';

try {
    $pdo = new PDO("sqlite:" . $dbPath);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // 1. Criar Tabelas
    $pdo->exec("CREATE TABLE IF NOT EXISTS usuarios (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        nome TEXT NOT NULL,
        email TEXT NOT NULL UNIQUE,
        senha TEXT NOT NULL,
        data_nascimento TEXT
    )");

    $pdo->exec("CREATE TABLE IF NOT EXISTS servicos (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        nome TEXT NOT NULL,
        preco REAL NOT NULL,
        imagem TEXT
    )");

    $pdo->exec("CREATE TABLE IF NOT EXISTS profissionais (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        nome TEXT NOT NULL,
        nota REAL NOT NULL
    )");

    $pdo->exec("CREATE TABLE IF NOT EXISTS servico_profissional (
        servico_id INTEGER,
        profissional_id INTEGER,
        PRIMARY KEY (servico_id, profissional_id)
    )");

    $pdo->exec("CREATE TABLE IF NOT EXISTS agendamentos (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        usuario_id INTEGER NOT NULL,
        servico_id INTEGER NOT NULL,
        profissional_id INTEGER NOT NULL,
        data_hora TEXT NOT NULL,
        status TEXT NOT NULL DEFAULT 'Pendente',
        created_at TEXT DEFAULT CURRENT_TIMESTAMP
    )");

    // 2. Limpar dados antigos para reinicialização limpa
    $pdo->exec("DELETE FROM servicos");
    $pdo->exec("DELETE FROM profissionais");
    $pdo->exec("DELETE FROM servico_profissional");

    // 3. Inserir Serviços base
    $sqlServico = "INSERT INTO servicos (id, nome, preco, imagem) VALUES (:id, :nome, :preco, :imagem)";
    $stmtServico = $pdo->prepare($sqlServico);
    
    $servicos = [
        ['id' => 1, 'nome' => 'Corte de Cabelo e Tratamento Capilar', 'preco' => 190.00, 'imagem' => './img/cabelo.jpg'],
        ['id' => 2, 'nome' => 'Manicure', 'preco' => 52.00, 'imagem' => './img/manicure.jpg'],
        ['id' => 3, 'nome' => 'Estética', 'preco' => 120.00, 'imagem' => './img/estetica.jpg'],
        ['id' => 4, 'nome' => 'Pedicure', 'preco' => 60.00, 'imagem' => './img/pedicure.jpg']
    ];
    foreach ($servicos as $s) {
        $stmtServico->execute($s);
    }

    // 4. Inserir Profissionais
    $sqlProf = "INSERT INTO profissionais (id, nome, nota) VALUES (:id, :nome, :nota)";
    $stmtProf = $pdo->prepare($sqlProf);
    
    $profissionais = [
        ['id' => 1, 'nome' => 'Vanessa', 'nota' => 4.8],
        ['id' => 2, 'nome' => 'Amanda', 'nota' => 4.9],
        ['id' => 3, 'nome' => 'Adriana', 'nota' => 4.7]
    ];
    foreach ($profissionais as $p) {
        $stmtProf->execute($p);
    }

    // 5. Associar Serviços e Profissionais
    $sqlAssoc = "INSERT INTO servico_profissional (servico_id, profissional_id) VALUES (:servico_id, :profissional_id)";
    $stmtAssoc = $pdo->prepare($sqlAssoc);
    
    $associacoes = [
        // Corte Feminino (id 1) -> Vanessa (1), Amanda (2)
        ['servico_id' => 1, 'profissional_id' => 1],
        ['servico_id' => 1, 'profissional_id' => 2],
        // Manicure (id 2) -> Adriana (3), Vanessa (1)
        ['servico_id' => 2, 'profissional_id' => 3],
        ['servico_id' => 2, 'profissional_id' => 1],
        // Estética (id 3) -> Amanda (2)
        ['servico_id' => 3, 'profissional_id' => 2],
        // Pedicure (id 4) -> Adriana (3)
        ['servico_id' => 4, 'profissional_id' => 3]
    ];
    foreach ($associacoes as $a) {
        $stmtAssoc->execute($a);
    }

    // 6. Cadastrar usuário teste básico (senha hash simples)
    // Se o usuário não existir
    $stmtUser = $pdo->prepare("SELECT id FROM usuarios WHERE email = 'cliente@teste.com'");
    $stmtUser->execute();
    if (!$stmtUser->fetch()) {
        $senhaHash = password_hash('123456', PASSWORD_DEFAULT);
        $pdo->exec("INSERT INTO usuarios (nome, email, senha, data_nascimento) 
            VALUES ('Cliente Teste', 'cliente@teste.com', '$senhaHash', '1995-10-15')");
    }

    echo json_encode([
        'status' => 'success',
        'message' => 'Banco de dados inicializado e mocks carregados com sucesso!',
        'usuario_teste' => 'cliente@teste.com / senha: 123456'
    ]);

} catch (PDOException $e) {
    http_response_code(500);
    echo json_encode([
        'status' => 'error',
        'message' => 'Erro na configuração do banco: ' . $e->getMessage()
    ]);
}
