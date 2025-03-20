-- Encontre os nomes de todos os empregados que trabalham para o departamento de Engenharia Civil.

SELECT nome
FROM empregado
WHERE depto = 2;

-- Para todos os projetos localizados em “São Paulo”, listar os números dos projetos, os números dos departamentos, e o nome do gerente do departamento.

SELECT 
    p.numero AS numero_projeto,
    dp.numero_dpto AS numero_departamento,
    e.nome AS nome_gerente
FROM projeto p
JOIN departamento_projeto dp ON p.numero = dp.numero_projeto
JOIN departamento d ON dp.numero_dpto = d.numero
JOIN empregado e ON d.rg_gerente = e.rg
WHERE p.localizacao = 'São Paulo';

--  Encontre os empregados que trabalham em todos os projetos controlados pelo departamento número 3.

SELECT e.nome
FROM empregado e
WHERE NOT EXISTS (
    SELECT 1
    FROM departamento_projeto dp
    WHERE dp.numero_dpto = 3
    AND NOT EXISTS (
        SELECT 1
        FROM empregado_projeto ep
        WHERE ep.rg_empregado = e.rg
        AND ep.numero_projeto = dp.numero_projeto
    )
);

-- Liste os nomes dos empregados que não possuem dependentes.

SELECT e.nome
FROM empregado e
LEFT JOIN dependentes d ON e.rg = d.rg_responsavel
WHERE d.rg_responsavel IS NULL;

-- Liste os nomes dos gerentes que têm pelo menos
-- um dependente.

SELECT e.nome
FROM empregado e
JOIN departamento d ON e.rg = d.rg_gerente
JOIN dependentes dep ON e.rg = dep.rg_responsavel
GROUP BY e.nome
HAVING COUNT(dep.nome_dependente) > 0;

-- Selecione o número do departamento que controla projetos localizados em Rio Claro.

SELECT dp.numero_dpto
FROM departamento_projeto dp
JOIN projeto p ON dp.numero_projeto = p.numero
WHERE p.localizacao = 'Rio Claro';

-- Selecione o nome e o RG de todos os funcionários que são supervisores.
     
SELECT e.nome, e.rg
FROM empregado e
WHERE e.rg IN (SELECT DISTINCT rg_supervisor FROM empregado WHERE rg_supervisor IS NOT NULL);

-- Selecione todos os empregados com salário maior ou igual a 2000,00.
    
SELECT nome, rg, salario
FROM empregado
WHERE salario >= 2000.00;

-- Selecione todos os empregados cujo nome começa com ‘J’.

SELECT nome, rg
FROM empregado
WHERE nome LIKE 'J%';

-- Mostre todos os empregados que têm ‘Luiz’ ou ‘Luis’ no nome.

SELECT nome, rg
FROM empregado
WHERE nome LIKE '%Luiz%' OR nome LIKE '%Luis%';

-- Mostre todos os empregados do departamento de ‘Engenharia Civil’.

SELECT e.nome, e.rg, e.salario
FROM empregado e
JOIN departamento d ON e.depto = d.numero
WHERE d.nome = 'Engenharia Civil';

-- Mostre todos os nomes dos departamentos envolvidos com o projeto ‘Motor 3’.

SELECT d.nome
FROM departamento d
JOIN departamento_projeto dp ON d.numero = dp.numero_dpto
JOIN projeto p ON dp.numero_projeto = p.numero
WHERE p.nome = 'Motor 3';

-- Liste o nome dos empregados envolvidos com o projeto ‘Financeiro 1’.

SELECT e.nome
FROM empregado e
JOIN empregado_projeto ep ON e.rg = ep.rg_empregado
JOIN projeto p ON ep.numero_projeto = p.numero
WHERE p.nome = 'Financeiro 1';

-- Mostre os funcionários cujo supervisor ganha entre 2000 e 2500.

SELECT e.nome, e.rg
FROM empregado e
JOIN empregado s ON e.rg_supervisor = s.rg
WHERE s.salario BETWEEN 2000 AND 2500;

-- liste o nome dos gerentes que têm ao menos um dependente.

SELECT e.nome
FROM empregado e
JOIN departamento d ON e.rg = d.rg_gerente
JOIN dependentes dep ON e.rg = dep.rg_responsavel
GROUP BY e.nome;

-- Atualize o salário de todos os empregados que trabalham no departamento 2 para R$ 3.000,00.

UPDATE empregado
SET salario = 3000.00
WHERE depto = 2;

-- Fazer um comando SQL para ajustar o salário de todos os funcionários da empresa em 10%.

UPDATE empregado
SET salario = salario * 1.10;

-- Mostre a média salarial dos empregados da empresa.

SELECT AVG(salario) AS media_salarial
FROM empregado;

-- Mostre os nomes dos empregados (em ordem alfabética)  com salário maior que a média.

SELECT nome
FROM empregado
WHERE salario > (SELECT AVG(salario) FROM empregado)
ORDER BY nome;



