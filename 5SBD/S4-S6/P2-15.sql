SELECT
    cliente_nome,
    cidade,
    CASE
        WHEN cidade = 'Niterói' THEN 'Região Metropolitana'
        WHEN cidade = 'Resende' THEN 'Interior'
        ELSE 'Outra Região'
    END AS regiao
FROM
    cliente
ORDER BY
    regiao, cliente_nome;