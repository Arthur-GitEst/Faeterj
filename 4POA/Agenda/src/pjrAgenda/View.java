package pjrAgenda;
import java.io.BufferedWriter;
import java.io.File;
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
                // case 2 -> removerEvento();
                case 3 -> System.out.println("Programa Encerrado.");
                default -> System.out.println("Opção inválida.");
            }
        } while (opcao != 5);
    }

    public void inserirEvento() {
        System.out.println("Descrição do Evento: ");
        String descricao = scanner.nextLine();
        System.out.println("Data do Evento: ");
        String data = scanner.nextLine();
        System.out.println("Horário do Evento: ");
        String horario = scanner.nextLine();

        try {
            File arq = new File("Arquivo/arq.txt");
            FileWriter escrita = new FileWriter(arq, true);
            BufferedWriter bwEscrita = new BufferedWriter(escrita);
            bwEscrita.write(descricao + " ------------------------- " + data + " (" + horario + ")");
            bwEscrita.newLine();
            bwEscrita.close();
            escrita.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // public void teste(String descricao) {
    //     try {
    //         FileReader leitura = new FileReader(".../Arquivo/arq.txt");
    //         BufferedReader brLeitura = new BufferedReader(leitura);
    //         FileWriter escrita = new FileWriter(".../Arquivo/arq.txt", true);
    //         BufferedWriter bwEscrita = new BufferedWriter(escrita);
    
    //         String str;
    //         while ((str = brLeitura.readLine()) != null) {
    //             String[] lStr = str.split("\\s+");
    //             if (lStr.length > 0 && lStr[0].equals(descricao)) {
    //                 continue;
    //             }
    //             bwEscrita.write(str);
    //             bwEscrita.newLine();
    //         }
    //     } catch (IOException e) {
    //         e.printStackTrace();
    //     }  
    // } 

    // public void removerEvento() {
    //     System.out.println("Evento a ser removido (insira a descrição): ");
    //     String evento = scanner.nextLine();

    //     removerLinha(evento);
    // }

    // public void removerLinha(String descricao) {
    //     try {
    //         FileReader leitura = new FileReader(".../Arquivo/arq.txt");
    //         BufferedReader brLeitura = new BufferedReader(leitura);
    //         FileWriter escrita = new FileWriter(".../Arquivo/arqTemp.txt", true);
    //         BufferedWriter bwEscrita = new BufferedWriter(escrita);
    //         String str;
    //         while ((str = brLeitura.readLine()) != null) {
    //             String[] partes = str.split(";");
                
    //             if (!partes[0].equals(descricao)){
    //                 bwEscrita.write(str);
    //                 bwEscrita.newLine();
    //             }
    //         }
    //         brLeitura.close();
    //         leitura.close();
    //         bwEscrita.close();
    //         escrita.close();
    //     } catch (IOException e) {
    //         e.printStackTrace();
    //     }
    // }
       
    

    // public void PrincipalLeituraArquivo() {
    //     try {

    //         FileReader leitura = new FileReader(".../Arquivo/arq.txt");
    //         BufferedReader brLeitura = new BufferedReader(leitura);
    //         while (brLeitura.ready()) {
    //             String str = brLeitura.readLine();
    //             System.out.println(str);

    //         }

    //         brLeitura.close();
    //         leitura.close();

    //     } catch (

    //     FileNotFoundException e) {
    //         e.printStackTrace();
    //     } catch (IOException e) {
    //         e.printStackTrace();
    //     }
    // }
}

