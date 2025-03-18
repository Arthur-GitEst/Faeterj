package model;

public class Data {
	int dia;
	int mes;
	int ano;
	String horario;
	
	public Data (int dia, int mes, int ano, String horario) {
		this.dia = dia;
		this.mes = mes;
		this.ano = ano;
		this.horario = horario;
	}
	
	//Setters
	  public void setDia(int dia){
	    this.dia = dia;
	  }

	  public void setMes(int mes){
	    this.mes = mes;
	  }

	  public void setAno(int ano){
	    this.ano = ano;
	  }

	  public void setHorario(String horario){
	    this.horario = horario;
	  }

	  //Getters
	  public int getDia() {
	    return dia;
	  }
	  
	  public int getMes(){
	    return mes;
	  }

	  public int getAno(){
	    return ano;
	  }

	  public String getHorario(){
	    return horario;
	  }
	  
	  public void mostrarData() {
	    System.out.println("Dia: " + getDia());
	    System.out.println("Mês: " + getMes());
	    System.out.println("Ano: " + getAno());
	    System.out.println("Horário: " + getHorario());
	  }
}
