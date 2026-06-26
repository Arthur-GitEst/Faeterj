<?php

header('Content-Type: application/json; charset=utf-8');

try {
    $dbPath = __DIR__ . '/../salon.db';
    $pdo = new PDO("sqlite:" . $dbPath);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Buscar todos os serviços
    $servicos = $pdo->query("SELECT * FROM servicos ORDER BY id ASC")->fetchAll(PDO::FETCH_ASSOC);

    // Para cada serviço, buscar os profissionais associados
    foreach ($servicos as &$s) {
        $stmt = $pdo->prepare("SELECT p.id, p.nome, p.nota 
                               FROM profissionais p 
                               INNER JOIN servico_profissional sp ON p.id = sp.profissional_id 
                               WHERE sp.servico_id = :servico_id");
        $stmt->execute(['servico_id' => $s['id']]);
        $s['profissionais'] = $stmt->fetchAll(PDO::FETCH_ASSOC);
    }

    echo json_encode($servicos);

} catch (Exception $e) {
    http_response_code(500);
    echo json_encode([
        'status' => 'error',
        'message' => 'Erro ao buscar serviços e profissionais: ' . $e->getMessage()
    ]);
}
