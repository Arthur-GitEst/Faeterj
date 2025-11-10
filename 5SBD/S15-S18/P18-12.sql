-- Mascarar os seis primeiros dígitos do CPF, mantendo os últimos três visíveis, para todos os clientes.

SELECT
  cliente_nome,
  RPAD('*', 6, '*') || SUBSTR(cliente_cpf, 7, LENGTH(cliente_cpf) - 9) || SUBSTR(cliente_cpf, -3) AS cpf_mascarado
FROM cliente;