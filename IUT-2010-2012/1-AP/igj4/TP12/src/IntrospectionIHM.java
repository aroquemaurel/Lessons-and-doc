import java.awt.BorderLayout;
import java.awt.Dimension;

import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTree;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.DefaultTreeModel;


public class IntrospectionIHM extends JPanel {
	private JPanel _pnTelechargement;
	private JScrollPane _pnArbre;
	private JTree _jtIntrospection;
	
	public IntrospectionIHM(){
		setLayout(new BorderLayout());
		_pnTelechargement = new JPanel();
		_pnArbre = new JScrollPane();
		add(_pnTelechargement, BorderLayout.NORTH);
		_pnTelechargement.add(new JLabel("Fichier jar à introspecter: "));
		JButton btChoisirFichier = new JButton("Choisir le fichier jar");
		_pnTelechargement.add(btChoisirFichier);
		
		add(_pnArbre, BorderLayout.SOUTH);
		_pnArbre.setPreferredSize(new Dimension(500, 600));
		_jtIntrospection = new JTree();
		
		
	}

}
