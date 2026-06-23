<?php

session_start();
header('Content-Type: application/json; charset=utf-8');

$action = isset($_GET['action']) ? $_GET['action'] : '';

switch ($action) {
    case 'check':
        if (isset($_SESSION['usuario_id'])) {
            echo json_encode([
                'logged_in' => true,
                'user' => [
                    'id' => $_SESSION['usuario_id'],
                    'nome' => $_SESSION['usuario_nome'],
                    'email' => $_SESSION['usuario_email']
                ]
            ]);
        } else {
            echo json_encode(['logged_in' => false]);
        }
        break;

    case 'login':
        $dados = json_decode(file_get_contents("php://input"), true);
        $email = isset($dados['email']) ? trim($dados['email']) : '';
        $senha = isset($dados['senha']) ? $dados['senha'] : '';

        if (empty($email) || empty($senha)) {
            http_response_code(400);
            echo json_encode(['status' => 'error', 'message' => 'Preencha todos os campos.']);
            exit();
        }

        // Autenticação simulada simples: aceita qualquer login não-vazio
        $nome = explode('@', $email)[0];
        $nome = ucfirst($nome);

        $_SESSION['usuario_id'] = 1;
        $_SESSION['usuario_nome'] = $nome;
        $_SESSION['usuario_email'] = $email;

        echo json_encode([
            'status' => 'success',
            'message' => 'Login simulado efetuado!',
            'user' => [
                'id' => 1,
                'nome' => $nome,
                'email' => $email
            ]
        ]);
        break;

    case 'register':
        $dados = json_decode(file_get_contents("php://input"), true);
        $nome = isset($dados['nome']) ? trim($dados['nome']) : '';
        $email = isset($dados['email']) ? trim($dados['email']) : '';
        $senha = isset($dados['senha']) ? $dados['senha'] : '';

        if (empty($nome) || empty($email) || empty($senha)) {
            http_response_code(400);
            echo json_encode(['status' => 'error', 'message' => 'Todos os campos são obrigatórios.']);
            exit();
        }

        $_SESSION['usuario_id'] = 1;
        $_SESSION['usuario_nome'] = $nome;
        $_SESSION['usuario_email'] = $email;

        echo json_encode([
            'status' => 'success',
            'message' => 'Cadastro simulado efetuado!',
            'user' => [
                'id' => 1,
                'nome' => $nome,
                'email' => $email
            ]
        ]);
        break;

    case 'logout':
        session_destroy();
        echo json_encode(['status' => 'success', 'message' => 'Sessão encerrada com sucesso.']);
        break;

    default:
        http_response_code(400);
        echo json_encode(['status' => 'error', 'message' => 'Ação inválida.']);
        break;
}
