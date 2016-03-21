/*
*
* Created by maxmya 21/3/2016
*/
import java.awt.*;
import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class Server extends JFrame {

    private JPanel contentPane;
    ServerSocket serverSocket;
    ObjectOutputStream oos;
    ObjectInputStream ois;
    JTextArea screen;
    JTextArea msges;
    String me;
    String partner;
    static int port = 1;
    static String name = "No Name";


    /**
     * Launch the application.
     */
    public static void main(String[] args) {
        EventQueue.invokeLater(new Runnable() {
            public void run() {
                try {
                    Dimension dim = Toolkit.getDefaultToolkit().getScreenSize();
                    JFrame start = new JFrame("Simple Chat");
                    start.setLayout(new FlowLayout());
                    JLabel portlLabel = new JLabel("Port");
                    JTextField portTextField = new JTextField(10);
                    JLabel namelLabel = new JLabel("Name");
                    JTextField nameField = new JTextField(10);
                    JButton sub = new JButton("Submit");
                    start.add(portlLabel);
                    start.add(portTextField);
                    start.add(namelLabel);
                    start.add(nameField);
                    start.add(sub);
                    start.setSize(150, 150);
                    start.setResizable(false);
                    start.setLocation(dim.width/2-start.getSize().width/2, dim.height/2-start.getSize().height/2);
                    start.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

                    sub.addActionListener(new ActionListener() {
                        @Override
                        public void actionPerformed(ActionEvent actionEvent) {
                            port = Integer.parseInt(portTextField.getText());
                            name = nameField.getText();
                            try {
                                start.setVisible(false);
                                Server frame = new Server(port, name);
                                frame.setVisible(true);

                            } catch (IOException e) {
                                JOptionPane.showMessageDialog(null, "Error ! "+e.getMessage());
                                System.exit(-1);

                            } catch (ClassNotFoundException e) {
                                JOptionPane.showMessageDialog(null, "Error ! "+e.getMessage());
                                System.exit(-1);


                            }


                        }
                    });

                    start.setVisible(true);


                } catch (Exception e) {
                    JOptionPane.showMessageDialog(null, "Error ! Pleas Correct your inputs");
                    System.exit(-1);

                }
            }
        });
    }

    /**
     * Create the frame.
     */
    public Server(int port, String name) throws IOException, ClassNotFoundException {

        me = name;
        serverSocket = new ServerSocket(port);
        System.out.println("Waiting Client!");
        Socket socket = serverSocket.accept();
        oos = new ObjectOutputStream(socket.getOutputStream());
        ois = new ObjectInputStream(socket.getInputStream());
        oos.writeObject(me);
        partner = (String) ois.readObject();


        //swing
        setResizable(false);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(100, 100, 467, 312);
        contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        setContentPane(contentPane);
        contentPane.setLayout(null);
        JPanel panel = new JPanel();
        panel.setBounds(12, 12, 426, 194);
        contentPane.add(panel);
        panel.setLayout(new CardLayout(0, 0));
        setTitle(me);
        Dimension dim = Toolkit.getDefaultToolkit().getScreenSize();
        this.setLocation(dim.width/2-this.getSize().width/2, dim.height/2-this.getSize().height/2);


        JScrollPane scrollPane_1 = new JScrollPane();
        panel.add(scrollPane_1, "name_19507103606401");

        screen = new JTextArea("");
        scrollPane_1.setViewportView(screen);
        screen.setEditable(false);


        JPanel panel_1 = new JPanel();
        panel_1.setBounds(12, 218, 297, 58);
        contentPane.add(panel_1);
        panel_1.setLayout(new CardLayout(0, 0));

        JScrollPane scrollPane = new JScrollPane();
        panel_1.add(scrollPane, "name_19394350651021");

        msges = new JTextArea();
        scrollPane.setViewportView(msges);
        msges.addKeyListener(
                new KeyListener() {

                    @Override
                    public void keyTyped(KeyEvent keyEvent) {

                    }

                    public void keyPressed(KeyEvent e) {

                        if (e.getKeyCode() == KeyEvent.VK_ENTER) {
                            send();

                        }
                    }

                    @Override
                    public void keyReleased(KeyEvent keyEvent) {

                    }
                }
        );

        JButton sendButton = new JButton("Send");
        sendButton.setBounds(321, 218, 117, 58);
        contentPane.add(sendButton);
        sendButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                send();
            }
        });

        connected();
    }

    void send() {
        String s = msges.getText();
        if (!s.equals("")) {
            try {
                oos.writeObject(s);
                screen.append("\n" + me + "  " + s);
                msges.setText(null);
            } catch (IOException e) {
                screen.setText("Cannot Send");
            }
        }
    }

    void connected() {
        Thread con = new Thread(new Runnable() {
            @Override
            public void run() {

                while (true) {
                    try {
                        String s = (String) ois.readObject();
                        screen.append("\n" + partner + "  " + s);
                    } catch (IOException e) {
                        JOptionPane.showMessageDialog(null, partner + " Disconnected");
                        System.exit(-1);
                    } catch (ClassNotFoundException e) {
                        JOptionPane.showMessageDialog(null, partner + " Disconnected");
                        System.exit(-1);
                    }
                }

            }
        });
        con.start();
    }

}
