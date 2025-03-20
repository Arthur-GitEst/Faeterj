package POB.exercicioArquivo.dominio;

public class Paciente {
    private int numero;
    private double peso;
    private double altura;

    public Paciente(int numero, double peso, double altura) {
        this.numero = numero;
        this.peso = peso;
        this.altura = altura;
    }

    public void listarPaciente() {
        System.out.println("Número: " + this.numero);
        System.out.println("Peso: " + this.peso);
        System.out.println("Altura: " + this.altura);
    }

    public int getNum() {
        return numero;
    }

    public double getPeso() {
        return peso;
    }
    
    public double getAltura() {
        return altura;
    }

    public void setPeso(double peso) {
        this.peso = peso;
    }

    public void setAltura(double altura) {
        this.altura = altura;
    }
}
