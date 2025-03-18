package pjrLeituraEscrita;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class PrincipalEscritaArquivo {
	public static void main(String[] args) {
		try {
			FileWriter escrita = new FileWriter("c:/teste/arq.txt", true);
			BufferedWriter bwEscrita = new BufferedWriter(escrita);
			bwEscrita.write("Teste");
			bwEscrita.newLine();
			bwEscrita.close();
			escrita.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}


