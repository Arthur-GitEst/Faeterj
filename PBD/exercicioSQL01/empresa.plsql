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

INSERT





