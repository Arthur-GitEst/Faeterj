<?php

session_start();
header('Content-Type: application/json; charset=utf-8');

$dbPath = __DIR__ . '/../salon.db';
$pdo = new PDO("sqlite:" . $dbPath);
$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

$method = $_SERVER['REQUEST_METHOD'];

// 1. GET - Buscar Dados de Agendamento ou Listar
if ($method === 'GET') {
    // Caso A: Buscar horários e profissionais por serviço para a tela de marcação
    if (isset($_GET['servico_id'])) {
        $servico_id = intval($_GET['servico_id']);
        
        // Detalhes do serviço
        $stmtServico = $pdo->prepare("SELECT * FROM servicos WHERE id = :servico_id");
        $stmtServico->execute(['servico_id' => $servico_id]);
        $servico = $stmtServico->fetch(PDO::FETCH_ASSOC);

        if (!$servico) {
            http_response_code(404);
            echo json_encode(['status' => 'error', 'message' => 'Serviço não encontrado.']);
            exit();
        }

        // Profissionais que prestam este serviço
        $stmtProf = $pdo->prepare("SELECT p.id, p.nome, p.nota FROM profissionais p 
            INNER JOIN servico_profissional sp ON p.id = sp.profissional_id 
            WHERE sp.servico_id = :servico_id");
        $stmtProf->execute(['servico_id' => $servico_id]);
        $profissionais = $stmtProf->fetchAll(PDO::FETCH_ASSOC);

        $horarios = ['09:15', '10:15', '11:30', '13:00', '14:30', '16:00'];

        echo json_encode([
            'status' => 'success',
            'servico' => $servico,
            'profissionais' => $profissionais,
            'horarios' => $horarios
        ]);
        exit();
    }

    // Caso B: Listar agendamentos do usuário logado (aba "Meu Perfil")
    if (isset($_SESSION['usuario_id'])) {
        $usuario_id = $_SESSION['usuario_id'];
        $stmt = $pdo->prepare("SELECT a.id, a.data_hora, a.status, 
            s.id AS servico_id, s.nome AS servico_nome, s.preco AS servico_preco, 
            p.id AS profissional_id, p.nome AS profissional_nome 
            FROM agendamentos a 
            INNER JOIN servicos s ON a.servico_id = s.id 
            INNER JOIN profissionais p ON a.profissional_id = p.id 
            WHERE a.usuario_id = :usuario_id 
            ORDER BY a.data_hora ASC");
        $stmt->execute(['usuario_id' => $usuario_id]);
        $agendamentos = $stmt->fetchAll(PDO::FETCH_ASSOC);

        echo json_encode($agendamentos);
    } else {
        http_response_code(401);
        echo json_encode(['status' => 'error', 'message' => 'Usuário não autenticado.']);
    }
    exit();
}

// 2. POST - Criar Agendamento (Simula o pagamento direto)
if ($method === 'POST') {
    if (!isset($_SESSION['usuario_id'])) {
        http_response_code(401);
        echo json_encode(['status' => 'error', 'message' => 'Por favor, faça login para agendar.']);
        exit();
    }

    $dados = json_decode(file_get_contents("php://input"), true);
    $usuario_id = $_SESSION['usuario_id'];
    $servico_id = isset($dados['servico_id']) ? intval($dados['servico_id']) : null;
    $profissional_id = isset($dados['profissional_id']) ? intval($dados['profissional_id']) : null;
    $data_hora = isset($dados['data_hora']) ? $dados['data_hora'] : ''; // Ex: "2026-06-22 09:15"

    if (!$servico_id || !$profissional_id || empty($data_hora)) {
        http_response_code(400);
        echo json_encode(['status' => 'error', 'message' => 'Dados de agendamento incompletos.']);
        exit();
    }

    // Inserir agendamento direto com status "Confirmado" (pago)
    $stmt = $pdo->prepare("INSERT INTO agendamentos (usuario_id, servico_id, profissional_id, data_hora, status) 
        VALUES (:usuario_id, :servico_id, :profissional_id, :data_hora, 'Confirmado')");
    $stmt->execute([
        'usuario_id' => $usuario_id,
        'servico_id' => $servico_id,
        'profissional_id' => $profissional_id,
        'data_hora' => $data_hora
    ]);

    echo json_encode(['status' => 'success', 'message' => 'Agendamento e pagamento concluídos com sucesso!']);
    exit();
}

// 3. PUT - Editar / Reagendar Horário
if ($method === 'PUT') {
    if (!isset($_SESSION['usuario_id'])) {
        http_response_code(401);
        echo json_encode(['status' => 'error', 'message' => 'Usuário não autenticado.']);
        exit();
    }

    $id = isset($_GET['id']) ? intval($_GET['id']) : null;
    if (!$id) {
        http_response_code(400);
        echo json_encode(['status' => 'error', 'message' => 'ID do agendamento não informado.']);
        exit();
    }

    $dados = json_decode(file_get_contents("php://input"), true);
    $usuario_id = $_SESSION['usuario_id'];
    $data_hora = isset($dados['data_hora']) ? $dados['data_hora'] : '';
    $profissional_id = isset($dados['profissional_id']) ? intval($dados['profissional_id']) : null;

    if (empty($data_hora) || !$profissional_id) {
        http_response_code(400);
        echo json_encode(['status' => 'error', 'message' => 'Dados para alteração incompletos.']);
        exit();
    }

    $stmt = $pdo->prepare("UPDATE agendamentos 
        SET data_hora = :data_hora, profissional_id = :profissional_id 
        WHERE id = :id AND usuario_id = :usuario_id");
    $stmt->execute([
        'data_hora' => $data_hora,
        'profissional_id' => $profissional_id,
        'id' => $id,
        'usuario_id' => $usuario_id
    ]);

    echo json_encode(['status' => 'success', 'message' => 'Agendamento reagendado com sucesso!']);
    exit();
}

// 4. DELETE - Excluir / Cancelar Agendamento
if ($method === 'DELETE') {
    if (!isset($_SESSION['usuario_id'])) {
        http_response_code(401);
        echo json_encode(['status' => 'error', 'message' => 'Usuário não autenticado.']);
        exit();
    }

    $id = isset($_GET['id']) ? intval($_GET['id']) : null;
    if (!$id) {
        http_response_code(400);
        echo json_encode(['status' => 'error', 'message' => 'ID do agendamento não informado.']);
        exit();
    }

    $usuario_id = $_SESSION['usuario_id'];
    $stmt = $pdo->prepare("DELETE FROM agendamentos WHERE id = :id AND usuario_id = :usuario_id");
    $stmt->execute([
        'id' => $id,
        'usuario_id' => $usuario_id
    ]);

    echo json_encode(['status' => 'success', 'message' => 'Agendamento cancelado com sucesso!']);
    exit();
}
