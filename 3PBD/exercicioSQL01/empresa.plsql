CREATE TABLE empregado (
    nome VARCHAR2(40 CHAR) NOT NULL,
    rg NUMBER(8) NOT NULL,
    cic NUMBER(8) NOT NULL,
    depto INTEGER NOT NULL,
    rg_supervisor NUMBER(8),
    salario FLOAT(5) NOT NULL
);

ALTER TABLE empregado ADD CONSTRAINT empregado_pk PRIMARY KEY (rg);

CREATE TABLE departamento (
    nome VARCHAR2(40 CHAR) NOT NULL,
    numero INTEGER NOT NULL,
    rg_gerente NUMBER(8) NOT NULL
);

ALTER TABLE departamento ADD CONSTRAINT departamento_pk PRIMARY KEY (numero);

CREATE TABLE projeto (
    nome VARCHAR2(40 CHAR) NOT NULL,
    numero INTEGER NOT NULL,
    localizacao VARCHAR2(40 CHAR) NOT NULL
);

ALTER TABLE projeto ADD CONSTRAINT projeto_pk PRIMARY KEY (numero);

CREATE TABLE dependentes (
    rg_responsavel NUMBER(8) NOT NULL,
    nome_dependente VARCHAR2(30 CHAR) NOT NULL,
    nascimento DATE NOT NULL,
    relacao VARCHAR2(15 CHAR) NOT NULL,
    sexo char NOT NULL
);

ALTER TABLE dependentes ADD CONSTRAINT dependentes_pk PRIMARY KEY (rg_responsavel, nome_dependente);

CREATE TABLE departamento_projeto (
    numero_dpto INTEGER NOT NULL,
    numero_projeto INTEGER NOT NULL
);

ALTER TABLE departamento_projeto ADD CONSTRAINT departamento_projeto_pk PRIMARY KEY (numero_dpto, numero_projeto);

CREATE TABLE empregado_projeto (
    rg_empregado NUMBER(8) NOT NULL,
    numero_projeto INTEGER NOT NULL,
    horas INTEGER NOT NULL
);

ALTER TABLE empregado_projeto ADD CONSTRAINT empregado_projeto_pk PRIMARY KEY (rg_empregado, numero_projeto);

ALTER TABLE departamento_projeto 
    ADD CONSTRAINT departamento_projeto_numero_dpto_fk FOREIGN KEY (numero_dpto)
         REFERENCES departamento (numero);
ALTER TABLE departamento_projeto
     ADD CONSTRAINT departamento_projeto_numero_projeto_fk FOREIGN KEY (numero_projeto)
         REFERENCES projeto (numero);

ALTER TABLE empregado_projeto 
    ADD CONSTRAINT empregado_projeto_rg_empregado_fk FOREIGN KEY (rg_empregado)
         REFERENCES empregado (rg);
ALTER TABLE empregado_projeto
    ADD CONSTRAINT empregado_projeto_numero_projeto_fk FOREIGN KEY (numero_projeto)
        REFERENCES projeto (numero);


INSERT ALL 
INTO empregado (nome, rg, cic, depto, rg_supervisor, salario) VALUES ('João Luiz', 10101010, 11111111, 1, NULL, 3000.00)
INTO empregado (nome, rg, cic, depto, rg_supervisor, salario) VALUES ('Fernando', 20202020, 22222222, 2, 10101010, 2500.00)
INTO empregado (nome, rg, cic, depto, rg_supervisor, salario) VALUES ('Ricardo', 30303030, 33333333, 2, 10101010, 2300.00)
INTO empregado (nome, rg, cic, depto, rg_supervisor, salario) VALUES ('Jorge', 40404040, 44444444, 2, 20202020, 4200.00)
INTO empregado (nome, rg, cic, depto, rg_supervisor, salario) VALUES ('Renato', 50505050, 55555555, 3, 20202020, 1300.00)
SELECT * FROM dual;

INSERT ALL
INTO departamento (nome, numero, rg_gerente) VALUES ('Contabilidade', 1, 10101010)
INTO departamento (nome, numero, rg_gerente) VALUES ('Engenharia Civil', 2, 30303030)
INTO departamento (nome, numero, rg_gerente) VALUES ('Engenharia
Mecânica', 3, 20202020)
SELECT * FROM dual;

INSERT ALL
INTO projeto (nome, numero, localizacao) VALUES ('Financeiro 1', 5, 'São Paulo')
INTO projeto (nome, numero, localizacao) VALUES ('Motor 3', 10, 'Rio Claro')
INTO projeto (nome, numero, localizacao) VALUES ('Prédio Central', 20, 'Campinas')
SELECT * FROM dual;

INSERT ALL
INTO dependentes (rg_responsavel, nome_dependente, nascimento, relacao, sexo) VALUES (10101010, 'Jorge', '12-27-86', 'Filho', 'M')
INTO dependentes (rg_responsavel, nome_dependente, nascimento, relacao, sexo) VALUES (10101010, 'Luiz', '11-18-79', 'Filho', 'M')
INTO dependentes (rg_responsavel, nome_dependente, nascimento, relacao, sexo) VALUES (20202020, 'Fernanda', '02-14-69', 'Cônjuge', 'F')
INTO dependentes (rg_responsavel, nome_dependente, nascimento, relacao, sexo) VALUES (20202020, 'Ângelo', '02-10-95', 'Filho', 'M')
INTO dependentes (rg_responsavel, nome_dependente, nascimento, relacao, sexo) VALUES (30303030, 'Adreia', '05-01-90', 'Filho', 'F')
SELECT * FROM dual;

INSERT ALL
INTO departamento_projeto (numero_dpto, numero_projeto) VALUES (2, 5)
INTO departamento_projeto (numero_dpto, numero_projeto) VALUES (3, 10)
INTO departamento_projeto (numero_dpto, numero_projeto) VALUES (2, 20)
SELECT * FROM dual;

INSERT ALL
INTO empregado_projeto (rg_empregado, numero_projeto, horas) VALUES (20202020, 5, 10)
INTO empregado_projeto (rg_empregado, numero_projeto, horas) VALUES (20202020, 10, 25)
INTO empregado_projeto (rg_empregado, numero_projeto, horas) VALUES (30303030, 5, 35)
INTO empregado_projeto (rg_empregado, numero_projeto, horas) VALUES (40404040, 20, 50)
INTO empregado_projeto (rg_empregado, numero_projeto, horas) VALUES (50505050, 20, 35)
SELECT * FROM dual;






