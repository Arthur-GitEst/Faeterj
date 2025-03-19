package view;

import java.util.Scanner;

import controller.ControleEvento;
import model.*;

public class EventoView {
    private final ControleEvento controller = new ControleEvento();

    private Scanner scanner = new Scanner(System.in);

    public void menu() {
        controller.carregarEventos();;
        int opcao;
        do {
            System.out.println("\n1. Inserir Evento");
            System.out.println("2. Listar Eventos");
            System.out.println("3. Remover Evento");
            System.out.println("4. Sair");
            System.out.print("Escolha uma opção: ");
            opcao = scanner.nextInt();
            scanner.nextLine();

            switch (opcao) {
                case 1 -> adicionarEvento();
                case 2 -> controller.listarEvento();
                case 3 -> controller.carregarEvento();();
                case 4 -> removerFuncionario();
                case 5 -> System.out.println("Programa Encerrado.");
                default -> System.out.println("Opção inválida.");
            }
        } while (opcao != 5);
    }

    public void adicionarEvento() {
        System.out.println("Descrição do Evento: ");
        String descricao = scanner.next();
        System.out.println("Dia do Evento: ");
        int dia = scanner.nextInt();
        System.out.println("Mês do Evento: ");
        int mes = scanner.nextInt();
        System.out.println("Ano do Evento: ");
        int ano = scanner.nextInt();
        System.out.println("Horário do Evento: ");
        String horario = scanner.next();

        Data data = new Data(dia, mes, ano, horario);
    }

    public void removerEvento() {
        
    }

}
