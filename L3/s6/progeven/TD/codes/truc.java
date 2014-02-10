Container c = f.getContentPane();
c.setLayout(new BorderLayout());

JLabel login = new JLabel("Login);
JTextField jtLogin = new JTextField();
JPanel panelLogin = new JPanel(new FlowLayout(FlowLayout.LEFT));
panelLogin.add(login);
panelLogin.add(csLogin);

JPanel pwd = new JLabel("password");
JPasswordField csPwd = new JPasswordField();

