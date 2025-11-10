-- Crie uma role chamada atendente_agencia com privilégios de SELECT em cliente e conta, e UPDATE no endereço do cliente.

CREATE ROLE atendente_agencia;

GRANT SELECT ON cliente TO atendente_agencia;
GRANT SELECT ON conta TO atendente_agencia;

GRANT UPDATE (rua, cidade) ON cliente TO atendente_agencia;