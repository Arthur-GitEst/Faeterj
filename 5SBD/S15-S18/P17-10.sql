-- Crie um usuário chamado auditor com privilégios para consultar qualquer view do banco.

CREATE USER auditor IDENTIFIED BY Senha123;

GRANT CREATE SESSION TO auditor;

GRANT SELECT ANY TABLE TO auditor;