import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

import POB.ProjetoAV2.model.Funcionario;

public class ControleEvento {
  private ArrayList<Evento> eventos;

  public void removerEvento(String nomeEvento) {
    for (Evento evento : eventos) {
      if (evento.getDescricao().equals(nomeEvento.toUpperCase())) {
        eventos.remove(evento);
        //salva dados
        return;
      }
    }
  }

  public ArrayList<Evento> carregarFuncionarios() {
        ArrayList<Evento> eventos = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader("eventos.txt"))) {
            String linha;
            while ((linha = reader.readLine()) != null) {
                funcionarios.add(Funcionario.fromFileString(linha));
            }
        } catch (FileNotFoundException e) {
            System.out.println("Arquivo de funcionarios não encontrado. Será criado ao salvar novos funcionarios.");
        } catch (IOException e) {
            System.out.println("Erro ao carregar funcionarios: " + e.getMessage());
        }
        return funcionarios;
    }
}
