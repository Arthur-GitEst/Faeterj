-- Mostre todas as agências, mesmo aquelas que não possuem clientes vinculados (junção externa esquerda).

SELECT agencia_nome, NVL(cliente_nome, 'Sem cliente')
FROM agencia
LEFT JOIN conta ON agencia_cod = agencia_agencia_cod
LEFT JOIN cliente ON cliente_cod = cliente_cliente_cod
ORDER BY agencia_nome