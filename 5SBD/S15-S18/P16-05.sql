-- Crie uma view chamada vw_emprestimos_grandes que exiba número do empréstimo, nome do cliente e valor dos empréstimos acima de R$ 20.000.

CREATE VIEW vw_emprestimos_grandes AS
SELECT
    e.emprestimo_numero,
    c.cliente_nome,
    e.quantia
FROM
    emprestimo e
JOIN
    cliente c ON e.cliente_cliente_cod = c.cliente_cod
WHERE
    e.quantia > 20000;