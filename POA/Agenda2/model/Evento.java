public class Evento {
  private String descricao;
  private Data data;

  public Evento(String descricao, Data data) {
    this.descricao = descricao;
    this.data = data;
  }

  //Setters
  public void setDescricao(String descricao){
    this.descricao = descricao;
  }

  public void setDescricao(Data data){
    this.data = data;
  }

  //Getters
  public Data getData() {
    return data;
  }
  
  public String getDescricao() {
    return descricao;
  }
  
  public void mostrarEvento() {
    System.out.println("Descrição: " + getDescricao());
    System.out.println("Data: " + getData().getDia() + "/" + getData().getMes() + "/" + getData().getAno() + "(" + getData().getHorario() + ")");
  }
}
