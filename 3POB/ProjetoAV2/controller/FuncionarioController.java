package POB.ProjetoAV2.controller;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Collections;

import POB.ProjetoAV2.model.*;

public class FuncionarioController {
    private List<Funcionario> funcionarios;
    private String arquivoFuncionarios = "POB/ProjetoAV2/funcionarios.txt";

    public FuncionarioController() {
        this.funcionarios = new ArrayList<>();
    }

    public void adicionarFuncionario(Funcionario funcionario) {
        funcionarios.add(funcionario);
        salvarDados();
    }

    public void listarFuncionarios() {
        if (funcionarios.isEmpty()) {
            System.out.println("Nenhum funcionário cadastrado.");
        } else {
            for (Funcionario funcionario : funcionarios) {
                funcionario.mostrarDetalhes();
            }
        }
    }

    public void atualizarFuncionario(String antigoNome, String novoNome, double novoSalario) {
        for (Funcionario funcionario : funcionarios) {
            if (funcionario.getNome().equals(antigoNome.toUpperCase())) {
                funcionario.setSalario(novoSalario);
                salvarDados();
                return;
            }
        }
        System.out.println("Funcionário não encontrado.");
    }

    public void removerFuncionario(String nome) {
        for (Funcionario funcionario : funcionarios) {
            if (funcionario.getNome().equals(nome.toUpperCase())) {
                funcionarios.remove(funcionario);
                salvarDados();
                return;
            }
        }
        System.out.println("Funcionário não encontrado.");
    }

    public void carregarDados() {
        try (BufferedReader reader = new BufferedReader(new FileReader(arquivoFuncionarios))) {
            String linha;
            while ((linha = reader.readLine()) != null) {
                String[] dados = linha.split(";");
                String tipo = dados[0];
                String nome = dados[1];
                double salario = Double.parseDouble(dados[2]);
                
                switch (tipo) {
                    case "D":
                        funcionarios.add(new Desenvolvedor(nome, salario));
                        break;
                    case "G":
                        funcionarios.add(new Gerente(nome, salario));
                        break;
                    case "T":
                        funcionarios.add(new Treinador(nome, salario));
                        break;
                    default:
                        throw new IllegalArgumentException("Tipo desconhecido: " + tipo);
                }
            }
        } catch (FileNotFoundException e) {
            System.out.println("Arquivo de pacientes não encontrado. Será criado ao salvar novos funcionários.");
        } catch (IOException e) {
            System.out.println("Erro ao carregar funcionários: " + e.getMessage());
        }
    }

    private void salvarDados() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(arquivoFuncionarios))) {
            for (Funcionario funcionario : funcionarios) {
                writer.write(funcionario.getTipo()  + ";" + funcionario.getNome() + ";" + funcionario.getSalario());
                writer.newLine();
            }
        } catch (IOException e) {
            System.out.println("Erro ao salvar pacientes: " + e.getMessage());
        }
    }
}
