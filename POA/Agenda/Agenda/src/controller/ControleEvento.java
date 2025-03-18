package controller;

import java.io.*;

import model.Data;
import model.Evento;
import java.util.ArrayList;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;


public class ControleEvento {
	private ArrayList<Evento> eventos;
	
	public ControleEvento() {
		eventos = new ArrayList<>();
	}
	
	public void adicionarEvento(Evento evento) {
		eventos.add(evento);
		SalvarEvento(eventos);
	}
	
	public void listarEvento() {
		for (Evento evento : eventos) {
			evento.mostrarEvento();
		}
	}
	
	public void SalvarEvento(ArrayList<Evento> eventos) {
		 try (BufferedWriter writer = new BufferedWriter(new FileWriter("eventos.txt"))) {
	            for (Evento evento : eventos) {
	                writer.write(evento.LinhaString());
	                writer.newLine();
	            }
	        } catch (IOException e) {
	            System.out.println("Erro ao salvar eventos: " + e.getMessage());
	        }
	}
	
	public void removerEvento(String nomeEvento) {
	    for (Evento evento : eventos) {
	      if (evento.getDescricao().equals(nomeEvento.toUpperCase())) {
	        eventos.remove(evento);
	        SalvarEvento(eventos);
	        return;
	      }
	    }
	}
	
    public void carregarEventos() {
        try (BufferedReader reader = new BufferedReader(new FileReader("eventos.txt"))) {
            String linha;
            while ((linha = reader.readLine()) != null) {
              String[] dados = linha.split(";");
							String descricao = dados[0];
							int dia = Integer.parseInt(dados[1]);
							int mes = Integer.parseInt(dados[2]);
							int ano = Integer.parseInt(dados[3]);
							int horario = Integer.parseInt(dados[4]);

							eventos.add(new Evento());
            }
        } catch (FileNotFoundException e) {
            System.out.println("Arquivo de funcionarios não encontrado. Será criado ao salvar novos funcionarios.");
        } catch (IOException e) {
            System.out.println("Erro ao carregar funcionarios: " + e.getMessage());
        }
        return eventos;
    }
    
}

