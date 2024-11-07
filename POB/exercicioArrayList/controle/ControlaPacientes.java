package POB.exercicioArrayList.controle;

import java.util.ArrayList;
import java.util.Scanner;

import POB.exercicioArrayList.dominio.Paciente;

public class ControlaPacientes {
    private ArrayList<Paciente> pacientes = new ArrayList<>();

    public ControlaPacientes() {
        this.pacientes = new ArrayList<>();
    }

    public void incluirPaciente(int numero, double peso, double altura) {
        Paciente paciente = new Paciente(numero, peso, altura);
        pacientes.add(paciente);
        System.out.println("Paciente Incluso!");
    }

    public void alterarPaciente(int numero) {
       Paciente paciente = buscarPaciente(numero);
       
       if (paciente != null) {
            Scanner ler = new Scanner(System.in);
            System.out.print("Novo peso do paciente: ");
            double peso = ler.nextDouble();
            System.out.print("Nova altura do paciente: ");
            double altura = ler.nextDouble();

            paciente.setPeso(peso);
            paciente.setAltura(altura);
            ler.close();
       } else {
            System.out.println("Paciente não encontrado.");
       }
    }

    public Paciente buscarPaciente(int numero) {
        for (Paciente paciente : pacientes) {
            if (paciente.getNum() == numero) {
                return paciente;
            }
        }
        return null;
    }

    public void excluirPaciente(int numero) {
        Paciente paciente = buscarPaciente(numero);

        if (paciente != null) {
            pacientes.remove(paciente);
            System.out.println("Paciente excluído com sucesso!");
        } else {
            System.out.println("Paciente não encontrado.");
        }
    }

    public void consultarPaciente(int numero) {
        if (pacientes.isEmpty()) {
            System.out.println("Lista Vazia.");
        } else {
            for (Paciente paciente : pacientes) {
                paciente.listarPaciente();
            }
        }
    }

    public static void main(String[] args) {
        ControlaPacientes controle = new ControlaPacientes();
        Scanner ler = new Scanner(System.in);
        int opcao;

        do {
            System.out.println("\n");
            System.out.println("1. Incluir Paciente");
            System.out.println("2. Alterar Paciente");
            System.out.println("3. Excluir Paciente");
            System.out.println("4. Consultar Paciente");
            System.out.println("0. Sair");
            System.out.print("Escolha uma opção: ");
            opcao = ler.nextInt();

            switch (opcao) {
                case 1:
                    System.out.print("Numero do Paciente: ");
                    int numero = ler.nextInt();
                    ler.nextLine(); // Limpa o buffer do scanner
                    System.out.print("Peso do Paciente: ");
                    double peso = ler.nextDouble();
                    System.out.print("Altura do Paciente: ");
                    double altura = ler.nextDouble();
                    controle.incluirPaciente(numero, peso, altura);
                    break;
                case 2:
                    System.out.print("Numero do Paciente: ");
                    int numeroAlterar = ler.nextInt();
                    controle.alterarPaciente(numeroAlterar);
                    break;
                case 3:
                    System.out.print("Numero do Paciente: ");
                    int numeroExcluir = ler.nextInt(); 
                    controle.excluirPaciente(numeroExcluir);
                    break;
                case 4: 
                    System.out.print("Numero do Paciente: ");
                    int numeroConsultar = ler.nextInt();
                    controle.consultarPaciente(numeroConsultar);
                    break;
                case 0:
                    System.out.println("Programa encerrado.");
                    break;
                default:
                    System.out.println("Opção Inválida.");
                    break;
            }
        } while (opcao != 0);
        ler.close();
    }
}
