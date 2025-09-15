package view;

import control.AviaoThread;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

@SuppressWarnings("serial")
public class Janela extends JFrame implements ActionListener {
  private JButton btnCorrida;
  private JButton btnCancel;
  private JLabel lblPista;
  private JLabel lblVelocimetro;
  private ImageIcon imgAviao1;
  private ImageIcon imgAviao2;
  private ImageIcon imgAviao3;
  private ImageIcon pista;
  private ImageIcon velocimetro;

  public Janela() {
    super();
    this.setLayout(null);
    this.setSize(1280, 650);
    this.setLocation(50, 50);
    this.setResizable(false);
    getContentPane().setBackground(Color.WHITE);

    this.setTitle("Corrida de Threads");
    velocimetro = new ImageIcon();
    pista = new ImageIcon();

    this.lblPista = new JLabel(pista);
    this.lblVelocimetro = new JLabel(velocimetro);
    this.lblVelocimetro.setBounds(200, 480, 150, 150);
    this.lblPista.setBounds(0, 0, 1280, 650);

    this.add(lblPista);
    this.lblPista.add(lblVelocimetro);

    this.lblPista.setBackground(Color.BLACK);

    this.btnCorrida = new JButton("Start Flight");
    this.btnCancel = new JButton("Stop Flight");
    this.btnCorrida.setBounds(500, 550, 120, 50);
    this.btnCancel.setBounds(640, 550, 120, 50);
    imgAviao1 = new ImageIcon();
    imgAviao2 = new ImageIcon();
    imgAviao3 = new ImageIcon();

    this.lblPista.add(btnCorrida);
    this.lblPista.add(btnCancel);

    this.setVisible(true);

    btnCorrida.addActionListener(this);
    btnCancel.addActionListener(this);

    JPanel jPanel = new JPanel();
    jPanel.setSize(300, 70);
    jPanel.setLayout(null);
    jPanel.setLocation(970, 510);
    jPanel.setBorder(BorderFactory.createTitledBorder("Grupo de Trabalho"));
    jPanel.setVisible(true);

    this.repaint();
  }

  public JLabel JLabelAvioes(String nome, ImageIcon img, int posX, int posY) {
    AviaoThread aviao = new AviaoThread(nome, img, posX, posY);
    aviao.setSize(256, 141);
    aviao.setVisible(true);
    this.add(aviao);
    return aviao;
  }

  @Override
  public void actionPerformed(ActionEvent dispara) {
    if (dispara.getSource() == this.btnCorrida) {
      this.lblPista.add(JLabelAvioes("Aviao1", imgAviao1, 0, 50));
      this.lblPista.add(JLabelAvioes("Aviao2", imgAviao2, 0, 200));
      this.lblPista.add(JLabelAvioes("Aviao3", imgAviao3, 0, 350));
    }
    if (dispara.getSource() == this.btnCancel) {
      System.exit(0);
    }
  }
}

