<?php
$file = 'perguntas.json';

function lerPerguntas($file) {
    if (!file_exists($file)) {
        return [];
    }
    $conteudo = file_get_contents($file);
    $dados = json_decode($conteudo, true);
    return is_array($dados) ? $dados : [];
}

function salvarPerguntas($file, $perguntas) {
    file_put_contents($file, json_encode($perguntas, JSON_PRETTY_PRINT | JSON_UNESCAPED_UNICODE));
}

$method = $_SERVER['REQUEST_METHOD'];
$payload = json_decode(file_get_contents('php://input'), true);

switch ($method) {
    case 'GET':
        $perguntas = lerPerguntas($file);

        if (isset($_GET['busca'])) {
            $busca = trim($_GET['busca']);
            if ($busca !== '') {
                $perguntas = array_values(array_filter($perguntas, function($item) use ($busca) {
                    return stripos($item['pergunta'], $busca) !== false;
                }));
            }
        }

        echo json_encode($perguntas);
        break;

    case 'POST':
        if (empty($payload['tipo']) || empty($payload['pergunta']) || empty($payload['resposta'])) {
            http_response_code(400);
            exit;
        }

        $perguntas = lerPerguntas($file);

        $novoId = 1;
        if (count($perguntas) > 0) {
            $ultimoItem = end($perguntas);
            $novoId = ($ultimoItem['id'] ?? 0) + 1;
        }

        $novaPergunta = [
            'id' => $novoId,
            'tipo' => $payload['tipo'],
            'pergunta' => $payload['pergunta'],
            'resposta' => $payload['resposta'],
            'falsas' => $payload['falsas'] ?? []
        ];

        $perguntas[] = $novaPergunta;
        salvarPerguntas($file, $perguntas);

        break;

    case 'PUT':
        if (empty($payload['id']) || empty($payload['pergunta']) || empty($payload['resposta'])) {
            http_response_code(400);
            exit;
        }

        $perguntas = lerPerguntas($file);
        $id = intval($payload['id']);
        $atualizado = false;

        foreach ($perguntas as &$item) {
            if (isset($item['id']) && intval($item['id']) === $id) {
                $item['pergunta'] = $payload['pergunta'];
                $item['resposta'] = $payload['resposta'];
                $atualizado = true;
                break;
            }
        }

        if ($atualizado) {
            salvarPerguntas($file, $perguntas);
        } else {
            http_response_code(404);
            exit;
        }
        break;

    case 'DELETE':
        $id = isset($_GET['id']) ? intval($_GET['id']) : null;

        if ($id === null) {
            http_response_code(400);
            exit;
        }

        $perguntas = lerPerguntas($file);
        $tamanhoOriginal = count($perguntas);

        $perguntas = array_values(array_filter($perguntas, function($item) use ($id) {
            return isset($item['id']) && intval($item['id']) !== $id;
        }));

        if (count($perguntas) < $tamanhoOriginal) {
            salvarPerguntas($file, $perguntas);
        } else {
            http_response_code(404);
            exit;
        }
        break;

    default:
        http_response_code(405);
        exit;
}
