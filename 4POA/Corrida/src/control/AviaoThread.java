package control;

import java.util.Random;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

public class AviaoThread extends JLabel implements Runnable {
  private Thread aviaoThread = null;
  private int posX;
  private int posY;
  private ImageIcon imagem;
  private static int pos = 0;
  private String nome;

  public AviaoThread(){}

  public AviaoThread(String nome, ImageIcon img, int posX, int posY) {
    super(img);
    this.nome = nome;
    this.imagem = img;
    this.posX = posX;
    this.posY = posY;

    aviaoThread = new Thread(this, nome);
    aviaoThread.start();
  }

  @Override
  public void run() {
    posX += new Random().nextInt(3) * 100;
    this.setLocation(posX, posY);

    if (posX >= 1280) {
      pos++;
      JOptionPane.showMessageDialog(null, pos + ")" + nome);
      return;
    }

    try {
      Thread.sleep(new Random().nextInt(5) * 100);
      run();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}
