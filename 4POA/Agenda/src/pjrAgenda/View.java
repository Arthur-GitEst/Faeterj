package pjrAgenda;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class View {
    private Scanner scanner = new Scanner(System.in);

    public void menu() {
        int opcao;
        do {
            System.out.println("\n1. Inserir Evento");
            System.out.println("2. Remover Evento");
            System.out.println("3. Sair");
            System.out.print("Escolha uma opção: ");
            opcao = scanner.nextInt();
            scanner.nextLine();

            switch (opcao) {
                case 1 -> inserirEvento();
                case 2  -> {
                    System.out.println("Qual a descrição do evento? ");
                    String descricao = scanner.nextLine();
                    removerEvento(descricao);
                }
                case 3 -> System.out.println("Programa Encerrado.");
                default -> System.out.println("Opção inválida.");
            }
        } while (opcao != 3);
    }

    public void inserirEvento() {
        System.out.println("Descrição do Evento: ");
        String descricao = scanner.nextLine();
        System.out.println("Data do Evento: ");
        String data = scanner.nextLine();
        System.out.println("Horário do Evento: ");
        String horario = scanner.nextLine();

        try {
            File arq = new File("4POA/Agenda/Arquivo/arq.txt");
            if(!arq.getParentFile().exists()) {
                arq.getParentFile().mkdirs();  
            } 
            FileWriter escrita = new FileWriter(arq, true);
            BufferedWriter bwEscrita = new BufferedWriter(escrita);
            bwEscrita.write(descricao.toUpperCase() + " ------------------------- " + data + " (" + horario + ")");
            bwEscrita.newLine();
            bwEscrita.close();
            escrita.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void removerEvento(String descricao) {
        File arquivoOriginal = new File("4POA/Agenda/Arquivo/arq.txt");
        if(!arquivoOriginal.exists()) {
            arquivoOriginal.getParentFile().mkdir();  
        } 
        File arquivoTemporario = new File("4POA/Agenda/Arquivo/arqTemp.txt");
        boolean sucesso = false;
        try ( BufferedReader brLeitura = new BufferedReader(new FileReader(arquivoOriginal));
            BufferedWriter bwEscrita = new BufferedWriter(new FileWriter(arquivoTemporario))){
            String str;

            while ((str = brLeitura.readLine()) != null) {
                String[] partes = str.split(" ------------------------- ");

                if (!partes[0].equals(descricao.toUpperCase())){
                    bwEscrita.write(str);
                    bwEscrita.newLine();
                }
            }
            sucesso = true;
            }catch (IOException e) {
                e.printStackTrace();
            }
            if (sucesso) {
                if (arquivoOriginal.delete()) {
                    arquivoTemporario.renameTo(arquivoOriginal);
            } else {
                System.out.println("Erro ao substituir o arquivo.");
            }
        }
    }
}

