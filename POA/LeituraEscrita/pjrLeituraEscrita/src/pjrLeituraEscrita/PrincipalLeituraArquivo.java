package pjrLeituraEscrita;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.LinkedList;

public class PrincipalLeituraArquivo {
	public static void main(String[] args) {
		try {

			FileReader leitura = new FileReader("c:/teste/arq.txt");
			BufferedReader brLeitura = new BufferedReader(leitura);
			while (brLeitura.ready()) {
				String str = brLeitura.readLine();
				System.out.println(str);

			}

			brLeitura.close();
			leitura.close();

		} catch (

		FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
