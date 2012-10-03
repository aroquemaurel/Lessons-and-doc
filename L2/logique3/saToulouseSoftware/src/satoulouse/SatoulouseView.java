/*
 * SatoulouseView.java
 */

package satoulouse;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.jdesktop.application.Action;
import org.jdesktop.application.ResourceMap;
import org.jdesktop.application.SingleFrameApplication;
import org.jdesktop.application.FrameView;
import org.jdesktop.application.TaskMonitor;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.util.ArrayList;
import javax.swing.Timer;
import javax.swing.Icon;
import javax.swing.JDialog;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.filechooser.FileFilter;

/**
 * The application's main frame.
 */
public class SatoulouseView extends FrameView {

    ArrayList<FormulaBox> formulaBoxes = new ArrayList<FormulaBox>();
    private int formulaBoxIndiceCourant = 0;
    private final PaletteForFormulas paletteForFormulas;

    public SatoulouseView(SingleFrameApplication app) {
        super(app);

        initComponents();

        paletteForFormulas = new PaletteForFormulas();
        jScrollPane2.setViewportView(paletteForFormulas);

        reset();



        


        getFrame().setTitle("SAToulouse");

        // status bar initialization - message timeout, idle icon and busy animation, etc
        ResourceMap resourceMap = getResourceMap();
        int messageTimeout = resourceMap.getInteger("StatusBar.messageTimeout");
        messageTimer = new Timer(messageTimeout, new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                statusMessageLabel.setText("");
            }
        });
        messageTimer.setRepeats(false);
        int busyAnimationRate = resourceMap.getInteger("StatusBar.busyAnimationRate");
        for (int i = 0; i < busyIcons.length; i++) {
            busyIcons[i] = resourceMap.getIcon("StatusBar.busyIcons[" + i + "]");
        }
        busyIconTimer = new Timer(busyAnimationRate, new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                busyIconIndex = (busyIconIndex + 1) % busyIcons.length;
                statusAnimationLabel.setIcon(busyIcons[busyIconIndex]);
            }
        });
        idleIcon = resourceMap.getIcon("StatusBar.idleIcon");
        statusAnimationLabel.setIcon(idleIcon);
        progressBar.setVisible(false);

        // connecting action tasks to status bar via TaskMonitor
        TaskMonitor taskMonitor = new TaskMonitor(getApplication().getContext());
        taskMonitor.addPropertyChangeListener(new java.beans.PropertyChangeListener() {
            public void propertyChange(java.beans.PropertyChangeEvent evt) {
                String propertyName = evt.getPropertyName();
                if ("started".equals(propertyName)) {
                    if (!busyIconTimer.isRunning()) {
                        statusAnimationLabel.setIcon(busyIcons[0]);
                        busyIconIndex = 0;
                        busyIconTimer.start();
                    }
                    progressBar.setVisible(true);
                    progressBar.setIndeterminate(true);
                } else if ("done".equals(propertyName)) {
                    busyIconTimer.stop();
                    statusAnimationLabel.setIcon(idleIcon);
                    progressBar.setVisible(false);
                    progressBar.setValue(0);
                } else if ("message".equals(propertyName)) {
                    String text = (String)(evt.getNewValue());
                    statusMessageLabel.setText((text == null) ? "" : text);
                    messageTimer.restart();
                } else if ("progress".equals(propertyName)) {
                    int value = (Integer)(evt.getNewValue());
                    progressBar.setVisible(true);
                    progressBar.setIndeterminate(false);
                    progressBar.setValue(value);
                }
            }
        });
    }

    @Action
    public void showAboutBox() {
        if (aboutBox == null) {
            JFrame mainFrame = SatoulouseApp.getApplication().getMainFrame();
            aboutBox = new SatoulouseAboutBox(mainFrame);
            aboutBox.setLocationRelativeTo(mainFrame);
        }
        SatoulouseApp.getApplication().show(aboutBox);
    }

    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        mainPanel = new javax.swing.JPanel();
        jScrollPane2 = new javax.swing.JScrollPane();
        jPanel2 = new javax.swing.JPanel();
        jPanel3 = new javax.swing.JPanel();
        jButton1 = new javax.swing.JButton();
        jScrollPaneFormulas = new javax.swing.JScrollPane();
        jPanelFormulas = new javax.swing.JPanel();
        menuBar = new javax.swing.JMenuBar();
        javax.swing.JMenu fileMenu = new javax.swing.JMenu();
        jMenuItem9 = new javax.swing.JMenuItem();
        jMenuItem15 = new javax.swing.JMenuItem();
        jMenuItem16 = new javax.swing.JMenuItem();
        javax.swing.JMenuItem exitMenuItem = new javax.swing.JMenuItem();
        jMenu1 = new javax.swing.JMenu();
        jMenuItem1 = new javax.swing.JMenuItem();
        jMenuItem2 = new javax.swing.JMenuItem();
        jMenuItem3 = new javax.swing.JMenuItem();
        jMenuItem4 = new javax.swing.JMenuItem();
        jMenuItem5 = new javax.swing.JMenuItem();
        jMenuItem10 = new javax.swing.JMenuItem();
        jMenuItem11 = new javax.swing.JMenuItem();
        jMenuItem6 = new javax.swing.JMenuItem();
        jMenu2 = new javax.swing.JMenu();
        jMenuItem7 = new javax.swing.JMenuItem();
        javax.swing.JMenu helpMenu = new javax.swing.JMenu();
        mnuHelp = new javax.swing.JMenuItem();
        javax.swing.JMenuItem aboutMenuItem = new javax.swing.JMenuItem();
        statusPanel = new javax.swing.JPanel();
        javax.swing.JSeparator statusPanelSeparator = new javax.swing.JSeparator();
        statusMessageLabel = new javax.swing.JLabel();
        statusAnimationLabel = new javax.swing.JLabel();
        progressBar = new javax.swing.JProgressBar();

        mainPanel.setName("mainPanel"); // NOI18N
        mainPanel.setLayout(new javax.swing.BoxLayout(mainPanel, javax.swing.BoxLayout.LINE_AXIS));

        jScrollPane2.setMaximumSize(new java.awt.Dimension(240, 32767));
        jScrollPane2.setName("jScrollPane2"); // NOI18N
        mainPanel.add(jScrollPane2);

        jPanel2.setName("jPanel2"); // NOI18N
        jPanel2.setLayout(new javax.swing.BoxLayout(jPanel2, javax.swing.BoxLayout.PAGE_AXIS));

        jPanel3.setName("jPanel3"); // NOI18N
        jPanel3.setLayout(new javax.swing.BoxLayout(jPanel3, javax.swing.BoxLayout.LINE_AXIS));

        org.jdesktop.application.ResourceMap resourceMap = org.jdesktop.application.Application.getInstance(satoulouse.SatoulouseApp.class).getContext().getResourceMap(SatoulouseView.class);
        jButton1.setFont(resourceMap.getFont("jButton1.font")); // NOI18N
        jButton1.setIcon(resourceMap.getIcon("jButton1.icon")); // NOI18N
        jButton1.setText(resourceMap.getString("jButton1.text")); // NOI18N
        jButton1.setFocusable(false);
        jButton1.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        jButton1.setName("jButton1"); // NOI18N
        jButton1.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });
        jPanel3.add(jButton1);

        jPanel2.add(jPanel3);

        jScrollPaneFormulas.setName("jScrollPaneFormulas"); // NOI18N

        jPanelFormulas.setName("jPanelFormulas"); // NOI18N
        jPanelFormulas.setLayout(new javax.swing.BoxLayout(jPanelFormulas, javax.swing.BoxLayout.PAGE_AXIS));
        jScrollPaneFormulas.setViewportView(jPanelFormulas);

        jPanel2.add(jScrollPaneFormulas);

        mainPanel.add(jPanel2);

        menuBar.setFocusable(false);
        menuBar.setName("menuBar"); // NOI18N

        fileMenu.setText(resourceMap.getString("fileMenu.text")); // NOI18N
        fileMenu.setFocusable(false);
        fileMenu.setName("fileMenu"); // NOI18N

        jMenuItem9.setText(resourceMap.getString("jMenuItem9.text")); // NOI18N
        jMenuItem9.setName("jMenuItem9"); // NOI18N
        jMenuItem9.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem9ActionPerformed(evt);
            }
        });
        fileMenu.add(jMenuItem9);

        jMenuItem15.setText(resourceMap.getString("jMenuItem15.text")); // NOI18N
        jMenuItem15.setName("jMenuItem15"); // NOI18N
        jMenuItem15.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem15ActionPerformed(evt);
            }
        });
        fileMenu.add(jMenuItem15);

        jMenuItem16.setText(resourceMap.getString("jMenuItem16.text")); // NOI18N
        jMenuItem16.setName("jMenuItem16"); // NOI18N
        jMenuItem16.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem16ActionPerformed(evt);
            }
        });
        fileMenu.add(jMenuItem16);

        javax.swing.ActionMap actionMap = org.jdesktop.application.Application.getInstance(satoulouse.SatoulouseApp.class).getContext().getActionMap(SatoulouseView.class, this);
        exitMenuItem.setAction(actionMap.get("quit")); // NOI18N
        exitMenuItem.setName("exitMenuItem"); // NOI18N
        fileMenu.add(exitMenuItem);

        menuBar.add(fileMenu);

        jMenu1.setText(resourceMap.getString("jMenu1.text")); // NOI18N
        jMenu1.setFocusable(false);
        jMenu1.setName("jMenu1"); // NOI18N

        jMenuItem1.setText(resourceMap.getString("jMenuItem1.text")); // NOI18N
        jMenuItem1.setName("jMenuItem1"); // NOI18N
        jMenuItem1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem1ActionPerformed(evt);
            }
        });
        jMenu1.add(jMenuItem1);

        jMenuItem2.setText(resourceMap.getString("jMenuItem2.text")); // NOI18N
        jMenuItem2.setName("jMenuItem2"); // NOI18N
        jMenuItem2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem2ActionPerformed(evt);
            }
        });
        jMenu1.add(jMenuItem2);

        jMenuItem3.setText(resourceMap.getString("jMenuItem3.text")); // NOI18N
        jMenuItem3.setName("jMenuItem3"); // NOI18N
        jMenuItem3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem3ActionPerformed(evt);
            }
        });
        jMenu1.add(jMenuItem3);

        jMenuItem4.setText(resourceMap.getString("jMenuItem4.text")); // NOI18N
        jMenuItem4.setName("jMenuItem4"); // NOI18N
        jMenuItem4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem4ActionPerformed(evt);
            }
        });
        jMenu1.add(jMenuItem4);

        jMenuItem5.setText(resourceMap.getString("jMenuItem5.text")); // NOI18N
        jMenuItem5.setName("jMenuItem5"); // NOI18N
        jMenuItem5.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem5ActionPerformed(evt);
            }
        });
        jMenu1.add(jMenuItem5);

        jMenuItem10.setText(resourceMap.getString("jMenuItem10.text")); // NOI18N
        jMenuItem10.setName("jMenuItem10"); // NOI18N
        jMenuItem10.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem10ActionPerformed(evt);
            }
        });
        jMenu1.add(jMenuItem10);

        jMenuItem11.setText(resourceMap.getString("jMenuItem11.text")); // NOI18N
        jMenuItem11.setName("jMenuItem11"); // NOI18N
        jMenuItem11.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem11ActionPerformed(evt);
            }
        });
        jMenu1.add(jMenuItem11);

        jMenuItem6.setText(resourceMap.getString("jMenuItem6.text")); // NOI18N
        jMenuItem6.setName("jMenuItem6"); // NOI18N
        jMenuItem6.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem6ActionPerformed(evt);
            }
        });
        jMenu1.add(jMenuItem6);

        menuBar.add(jMenu1);

        jMenu2.setText(resourceMap.getString("jMenu2.text")); // NOI18N
        jMenu2.setFocusable(false);
        jMenu2.setName("jMenu2"); // NOI18N

        jMenuItem7.setText(resourceMap.getString("jMenuItem7.text")); // NOI18N
        jMenuItem7.setName("jMenuItem7"); // NOI18N
        jMenuItem7.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem7ActionPerformed(evt);
            }
        });
        jMenu2.add(jMenuItem7);

        menuBar.add(jMenu2);

        helpMenu.setText(resourceMap.getString("helpMenu.text")); // NOI18N
        helpMenu.setFocusable(false);
        helpMenu.setName("helpMenu"); // NOI18N

        mnuHelp.setText(resourceMap.getString("mnuHelp.text")); // NOI18N
        mnuHelp.setName("mnuHelp"); // NOI18N
        mnuHelp.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                mnuHelpActionPerformed(evt);
            }
        });
        helpMenu.add(mnuHelp);

        aboutMenuItem.setAction(actionMap.get("showAboutBox")); // NOI18N
        aboutMenuItem.setText(resourceMap.getString("aboutMenuItem.text")); // NOI18N
        aboutMenuItem.setName("aboutMenuItem"); // NOI18N
        helpMenu.add(aboutMenuItem);

        menuBar.add(helpMenu);

        statusPanel.setName("statusPanel"); // NOI18N

        statusPanelSeparator.setName("statusPanelSeparator"); // NOI18N

        statusMessageLabel.setName("statusMessageLabel"); // NOI18N

        statusAnimationLabel.setHorizontalAlignment(javax.swing.SwingConstants.LEFT);
        statusAnimationLabel.setName("statusAnimationLabel"); // NOI18N

        javax.swing.GroupLayout statusPanelLayout = new javax.swing.GroupLayout(statusPanel);
        statusPanel.setLayout(statusPanelLayout);
        statusPanelLayout.setHorizontalGroup(
            statusPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(statusPanelSeparator, javax.swing.GroupLayout.DEFAULT_SIZE, 577, Short.MAX_VALUE)
            .addGroup(statusPanelLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(statusMessageLabel)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 557, Short.MAX_VALUE)
                .addComponent(statusAnimationLabel)
                .addContainerGap())
        );
        statusPanelLayout.setVerticalGroup(
            statusPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(statusPanelLayout.createSequentialGroup()
                .addComponent(statusPanelSeparator, javax.swing.GroupLayout.PREFERRED_SIZE, 2, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addGroup(statusPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(statusMessageLabel)
                    .addComponent(statusAnimationLabel))
                .addGap(3, 3, 3))
        );

        progressBar.setName("progressBar"); // NOI18N

        setComponent(mainPanel);
        setMenuBar(menuBar);
        setStatusBar(statusPanel);
    }// </editor-fold>//GEN-END:initComponents






    private FormulaBox getFocusFormulaBox()
    {
       
        for(FormulaBox fb : formulaBoxes)
        {
            if(fb.isFocusOwner())
                return fb;
        }
        
        return FormulaBox.getFocusOwnerFormulaBox();
    }

    



    private ArrayList<String> getArrayListFormulas()
    {
        ArrayList<String> s = new ArrayList<String>();
        for(FormulaBox f : formulaBoxes)
        {
            if(!f.isEmpty())
            {
                s.add(f.getText());
            }
        }
        return s;
    }






    
    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        if(!isOK())
        {
            JOptionPane.showMessageDialog(getFrame(), "Tatata ! Tu as des erreurs dans les formules que tu as entré. D'abord, tu me vérifies ça !!",
				      "Erreur",
				      JOptionPane.ERROR_MESSAGE);
            return;
        }

        WaitDialog w = new WaitDialog(getFrame(), false);
        w.setVisible(true);
        w.repaint();

        ArrayList<String> result;
    //    try {
            Chronometre.tickDebut();

            SATSolverSAT4J solver = new SATSolverSAT4J();
            System.out.println("On envoie au solveur");

            for(FormulaBox f : formulaBoxes)
                if(!f.isEmpty())
                 solver.addFormula(f.getFormulaForSAT4J());



            Chronometre.printDuree();
            
            try
             {
                result = solver.isSATFormulaInSchemeVar();
            } catch (Exception ex) {
                SchemeWithKawa.restart();
                JOptionPane.showMessageDialog(getFrame(), ex,
                                          "Erreur",
                                          JOptionPane.ERROR_MESSAGE);
                return;
            }
        SATResults d = new SATResults(getFrame(), true, result);
        w.setVisible(false);
        d.setVisible(true);
      //  String result = formulaBox1.getFormula().getString();
       
    }//GEN-LAST:event_jButton1ActionPerformed

    private void jMenuItem1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem1ActionPerformed
        
        reset();
        addFormula("(bigand i (1 2) (bigand j (1 2) (bigor n (1 2) (p i j n))))");
        addFormula("(bigand i (1 2) (bigand j (1 2) (bigand n (1 2)  (bigand m (1 2)  (m diff n) ((p i j n) imply (not (p i j m)))))))");
        addFormula("(bigand i (1 2) (bigand n (1 2)  (bigor j (1 2) (p i j n))))");
        addFormula("(bigand j (1 2) (bigand n (1 2)  (bigor i (1 2) (p i j n))))");
        addFormula("((p 1 1 2) and (p 1 2 1)) ");


    }//GEN-LAST:event_jMenuItem1ActionPerformed

    private void jMenuItem2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem2ActionPerformed
        reset();
        addFormula("(bigand i (1 2 3) (bigand j (1 2 3) (bigor n (1 2 3) (p i j n))))");
        addFormula("(bigand i (1 2 3) (bigand j (1 2 3) (bigand n (1 2 3)  (bigand m (1 2 3)  (m diff n) ((p i j n) imply (not (p i j m)))))))");
        addFormula("(bigand i (1 2 3) (bigand n (1 2 3)  (bigor j (1 2 3) (p i j n))))");
        addFormula("(bigand j (1 2 3) (bigand n (1 2 3)  (bigor i (1 2 3) (p i j n))))");
        addFormula("((((((((p 1 1 2) and (p 1 2 1)) and ((p 1 3 3) and (p 2 1 1))) and (p 2 2 3)) and (p 2 3 1)) and (p 3 1 1)) and (p 3 2 2)) and (p 3 3 3)) ");
    }//GEN-LAST:event_jMenuItem2ActionPerformed

    private void jMenuItem3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem3ActionPerformed
        reset();

        addFormula("(bigand i (1 .. 4) (bigand j (1 .. 4) (bigor n (1 .. 4) (p i j n))))");
        addFormula("(bigand i (1 .. 4) (bigand j (1 .. 4) (bigand n (1 .. 4)  (bigand m (1 .. 4)  (m diff n) ((p i j n) imply (not (p i j m)))))))");

        addFormula("(bigand n (1 .. 4) (bigand i (1 .. 4) (bigor j (1 .. 4) (p i j n))))");
        addFormula("(bigand n (1 .. 4) (bigand j (1 .. 4) (bigor i (1 .. 4) (p i j n))))");

        addFormula("(bigand n (1 .. 4) (bigor i (1 2) (bigor j (1 2) (p i j n))))");
        addFormula("(bigand n (1 .. 4) (bigor i (1 2) (bigor j (3 4) (p i j n))))");

        addFormula("(bigand n (1 .. 4) (bigor i (3 4) (bigor j (1 2) (p i j n))))");
        addFormula("(bigand n (1 .. 4) (bigor i (3 4) (bigor j (3 4) (p i j n))))");

        addFormula("((p 1 1 2) and ((p 1 3 2) and (p 3 4 4))) ");

    }//GEN-LAST:event_jMenuItem3ActionPerformed

    private void jMenuItem4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem4ActionPerformed
        reset();
addFormula("(bigand i (1 .. 9) (bigand j (1 .. 9) (bigor n (1 .. 9) (p i j n))))");
addFormula("(bigand i (1 .. 9) (bigand j (1 .. 9) (bigand n (1 .. 9)  (bigand m (1 .. 9)  (m diff n) ((p i j n) imply (not (p i j m)))))))");
addFormula("(bigand n (1 .. 9) (bigand i (1 .. 9) (bigor j (1 .. 9) (p i j n))))");
addFormula("(bigand n (1 .. 9) (bigand j (1 .. 9) (bigor i (1 .. 9) (p i j n))))");
//
addFormula("(bigand n (1 .. 9) (bigor i (1 .. 3) (bigor j (1 .. 3) (p i j n))))");
addFormula("(bigand n (1 .. 9) (bigor i (4 .. 6) (bigor j (1 .. 3) (p i j n))))");
addFormula("(bigand n (1 .. 9) (bigor i (7 .. 9) (bigor j (1 .. 3) (p i j n))))");
//
addFormula("(bigand n (1 .. 9) (bigor i (1 .. 3) (bigor j (4 .. 6) (p i j n))))");
addFormula("(bigand n (1 .. 9) (bigor i (4 .. 6) (bigor j (4 .. 6) (p i j n))))");
addFormula("(bigand n (1 .. 9) (bigor i (7 .. 9) (bigor j (4 .. 6) (p i j n))))");
//
addFormula("(bigand n (1 .. 9) (bigor i (1 .. 3) (bigor j (7 .. 9) (p i j n))))");
addFormula("(bigand n (1 .. 9) (bigor i (4 .. 6) (bigor j (7 .. 9) (p i j n))))");
addFormula("(bigand n (1 .. 9) (bigor i (7 .. 9) (bigor j (7 .. 9) (p i j n))))");
//
//
addFormula("((p 1 2 3) and (p 1 6 1) and (p 2 3 6) and (p 2 8 5) and (p 3 1 5) and (p 3 7 9) and (p 3 8 8))");
addFormula("((p 4 2 8) and (p 4 6 6) and (p 4 7 3) and (p 4 9 2) and (p 5 5 5) and (p 6 1 9) and (p 6 3 3) and (p 6 4 8) and (p 6 8 6))");
addFormula("((p 7 1 7) and (p 7 2 1) and (p 7 3 4) and (p 7 9 9) and (p 8 2 2) and (p 8 7 8) and (p 9 4 4) and (p 9 8 3))");
        
    }//GEN-LAST:event_jMenuItem4ActionPerformed

    private void jMenuItem5ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem5ActionPerformed
        reset();
addFormula("(bigand p (France Italie Suisse Allemagne Luxembourg Belgique Autriche) (bigor c (1 2 3) (p c)))");
addFormula("(bigand p (France Italie Suisse Allemagne Luxembourg Belgique Autriche) (bigand c (1 2 3 4) (bigand d (1 2 3 4) (d diff c) ((p c) imply (not (p d))))))");
addFormula("(bigand c (1 2 3 4) ((not (France c)) or (not (Allemagne c))))");
addFormula("(bigand c (1 2 3 4) ((not (Suisse c)) or (not (Allemagne c))))");
addFormula("(bigand c (1 2 3 4) ((not (France c)) or (not (Suisse c))))");
addFormula("(bigand c (1 2 3 4) ((not (Luxembourg c)) or (not (Allemagne c))))");
addFormula("(bigand c (1 2 3 4) ((not (France c)) or (not (Luxembourg c))))");
addFormula("(bigand c (1 2 3 4) ((not (France c)) or (not (Italie c))))");
addFormula("(bigand c (1 2 3 4) ((not (Suisse c)) or (not (Italie c))))");
addFormula("(bigand c (1 2 3 4) ((not (Italie c)) or (not (Autriche c))))");
addFormula("(bigand c (1 2 3 4) ((not (Luxembourg c)) or (not (Belgique c))))");
addFormula("(bigand c (1 2 3 4) ((not (Belgique c)) or (not (France c))))");
addFormula("(bigand c (1 2 3 4) ((not (Belgique c)) or (not (Allemagne c))))");
    }//GEN-LAST:event_jMenuItem5ActionPerformed

    private void jMenuItem9ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem9ActionPerformed
        reset();
    }//GEN-LAST:event_jMenuItem9ActionPerformed

    private void jMenuItem10ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem10ActionPerformed
        reset();
addFormula("(bigand t (0 .. 7) (((loup droite t) and (mouton droite t)) imply (barque droite t)))");
addFormula("(bigand t (0 .. 7) (((mouton droite t) and (chou droite t)) imply (barque droite t)))");
//
addFormula("(bigand t (0 .. 7) (((not (loup droite t)) and (not (mouton droite t))) imply (not (barque droite t))))");
addFormula("(bigand t (0 .. 7) (((not (mouton droite t)) and (not (chou droite t))) imply (not (barque droite t))))");
//
addFormula("(bigand o (barque chou loup mouton) (not (o droite 0)))");
addFormula("(bigand o (barque chou loup mouton) (o droite 7))");
//
addFormula("(bigand t (0 .. 6) (bigand o (chou loup mouton) ((barque droite t) imply ((not (o droite t)) imply (not (o droite (t + 1)))))))");
addFormula("(bigand t (0 .. 6) (bigand o (chou loup mouton) ((not (barque droite t)) imply ((o droite t) imply (o droite (t + 1))))))");
//
addFormula("(bigand t (0 .. 6) (bigand o (chou loup mouton) (bigand o2 (chou loup mouton) (o diff o2) ((not ((o droite t) equiv (o droite (t + 1)))) imply ((o2 droite t) equiv (o2 droite (t + 1)))))))");
addFormula("(bigand t (0 .. 6) ((barque droite t) equiv (not (barque droite (t + 1)))))");
    }//GEN-LAST:event_jMenuItem10ActionPerformed


    private void lireRessource(String filenameressource)
    {
        ArrayList<String> s;
        try {
            s = TextFile.lire_dans_une_ressource_lignes(filenameressource); // TODO add your handling code here:
            reset();
            for(int i = 0; i < s.size(); i++)
                 addFormula(s.get(i));
        } catch (FileNotFoundException ex) {
            Logger.getLogger(SatoulouseView.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(SatoulouseView.class.getName()).log(Level.SEVERE, null, ex);
        }

        
    }

    private void lireFichier(String chemin)
    {
        ArrayList<String> s;
        try {
            s = TextFile.lire_dans_un_fichier_lignes(chemin); // TODO add your handling code here:
            reset();
            for(int i = 0; i < s.size(); i++)
                 addFormula(s.get(i));
        } catch (FileNotFoundException ex) {
            Logger.getLogger(SatoulouseView.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(SatoulouseView.class.getName()).log(Level.SEVERE, null, ex);
        }


    }



    private void lireFichierCNF(String chemin)
    {
        ArrayList<String> s;
        try {
            s = TextFile.lire_dans_un_fichier_lignes(chemin); // TODO add your handling code here:
            reset();
            for(String clause : Formula.createListFormulaFromCNFFile(s))
            {
                addFormula(clause);
            }
        } catch (FileNotFoundException ex) {
            Logger.getLogger(SatoulouseView.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(SatoulouseView.class.getName()).log(Level.SEVERE, null, ex);
        }


    }

    private void sauvegarderFichier(String chemin)
    {
        ArrayList<String> s=        getArrayListFormulas();
        try {
            TextFile.string_ecrire_dans_fichier_lignes(s, chemin);
        } catch (IOException ex) {
            Logger.getLogger(SatoulouseView.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    
    private void jMenuItem11ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem11ActionPerformed
        lireRessource("resources/timetable.txt");
    }//GEN-LAST:event_jMenuItem11ActionPerformed



    private FileFilter getFileFilterSave()
    {
        return new FileFilter() {
            @Override
            public boolean accept(File f) {
                if(f.isDirectory())
                    return true;
                else
                    return f.getName().endsWith(".txt");
            }

            public String getDescription() {
                return "Fichier texte SAToulouse (*.txt)";
            }
        };
    }



    private FileFilter getFileFilterLoad()
    {
        return new FileFilter() {
            @Override
            public boolean accept(File f) {
                if(f.isDirectory())
                    return true;
                else
                    return f.getName().endsWith(".txt") || f.getName().endsWith(".cnf");
            }

            public String getDescription() {
                return "Fichier texte SAToulouse (*.txt) | Fichier DIMACS cnf (*.cnf)";
            }
        };
    }

    
    private void jMenuItem15ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem15ActionPerformed
        JFileChooser fc = new JFileChooser();

          fc.setDialogTitle("Ouvrir une liste de formules d'un fichier...");
         fc.setFileFilter(getFileFilterLoad());
         if(fc.showOpenDialog(null) == JFileChooser.APPROVE_OPTION)
          {
                String fichierNomAOuvrir = fc.getSelectedFile().getAbsolutePath();

                if(fichierNomAOuvrir.endsWith(".cnf"))
                {
                    lireFichierCNF(fichierNomAOuvrir);
                }
                else
                {
                    lireFichier(fichierNomAOuvrir);
                }
         }
    }//GEN-LAST:event_jMenuItem15ActionPerformed




    private String demanderFichierNomPourSauvegarder()
{
    JFileChooser fc = new JFileChooser();
    fc.setDialogTitle("Sauvegarder une liste de formules dans un fichier...");
    fc.setFileFilter(getFileFilterSave());
    if(fc.showSaveDialog(null) == JFileChooser.APPROVE_OPTION)
    {
        if(fc.getSelectedFile().getAbsolutePath().endsWith(".txt"))
        {
            return fc.getSelectedFile().getAbsolutePath();
        }
        else
        {
            return fc.getSelectedFile().getAbsolutePath() + ".txt";
        }

    }
    else
        return null;
    }









    private void jMenuItem16ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem16ActionPerformed
         String fichierNom = demanderFichierNomPourSauvegarder();
         if(fichierNom != null)
          {
                sauvegarderFichier(fichierNom);
         }
    }//GEN-LAST:event_jMenuItem16ActionPerformed

    private void jMenuItem6ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem6ActionPerformed
        lireRessource("resources/somme.txt");
    }//GEN-LAST:event_jMenuItem6ActionPerformed

    private void jMenuItem7ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem7ActionPerformed
        FormulaBox f = getFocusFormulaBox();

        if(f == null)
        {
            JOptionPane.showMessageDialog(getFrame(), "Sélectionne un endroit où écrire une formule");
            return;
        }

       
        DialogGrille2D g = new DialogGrille2D(getFrame(), true);
        g.setVisible(true);

        if(g.isOK())
        {
            f.insert(g.getFormulaString());
        }
    }//GEN-LAST:event_jMenuItem7ActionPerformed

    private void mnuHelpActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_mnuHelpActionPerformed
        Help.show("satoulouse.html");
    }//GEN-LAST:event_mnuHelpActionPerformed




    private boolean isOK()
    {
        for(FormulaBox f : formulaBoxes)
        {
            if(!f.isOK())
                return false;
        }
        return true;
    }












//
//    formulaBox1.setText("(bigand i (1 .. 9) (bigand j (1 .. 9) (bigor n (1 .. 9) (p i j n))))");
//        formulaBox2.setText("(bigand i (1 .. 9) (bigand j (1 .. 9) (bigand n (1 .. 9)  (bigand m (1 .. 9)  ( m diff n) ((p i j n) imply (not (p i j m)))))))");
//        formulaBox3.setText("(bigand i (1 .. 9) (bigand j (1 .. 9) (bigand n (1 .. 9) (bigand k (1 .. 9) ( k diff i) ((p i j n) imply (not (p k j n)))))))");
//        formulaBox4.setText("(bigand i (1 .. 9) (bigand j (1 .. 9) (bigand n (1 .. 9) (bigand l (1 .. 9) ( l diff  j) ((p i j n) imply (not (p i l n)))))))");
//
//        formulaBox5.setText("(bigand i (1 .. 3) (bigand j (1 .. 3) (bigand n (1 .. 9) (bigand k (1 .. 3) (bigand l (1 .. 3) (or (k diff i) (l diff j)) ((p i j n) imply (not (p k l n))))))))");
//        formulaBox6.setText("(bigand i (4 .. 6) (bigand j (1 .. 3) (bigand n (1 .. 9) (bigand k (4 .. 6) (bigand l (1 .. 3) (or (k diff i) (l diff j)) ((p i j n) imply (not (p k l n))))))))");
//        formulaBox6.setText("(bigand i (7 .. 9) (bigand j (1 .. 3) (bigand n (1 .. 9) (bigand k (7 .. 9) (bigand l (1 .. 3) (or (k diff i) (l diff j)) ((p i j n) imply (not (p k l n))))))))");
//
//        formulaBox7.setText("(bigand i (1 .. 3) (bigand j (4 .. 6) (bigand n (1 .. 9) (bigand k (1 .. 3) (bigand l (4 .. 6) (or (k diff i) (l diff j)) ((p i j n) imply (not (p k l n))))))))");
//        formulaBox8.setText("(bigand i (4 .. 6) (bigand j (4 .. 6) (bigand n (1 .. 9) (bigand k (4 .. 6) (bigand l (4 .. 6) (or (k diff i) (l diff j)) ((p i j n) imply (not (p k l n))))))))");
//        formulaBox9.setText("(bigand i (7 .. 9) (bigand j (4 .. 6) (bigand n (1 .. 9) (bigand k (7 .. 9) (bigand l (4 .. 6) (or (diff k i) (diff l j)) ((p i j n) imply (not (p k l n))))))))");
//
//        formulaBox10.setText("(bigand i (1 .. 3) (bigand j (7 .. 9) (bigand n (1 .. 9) (bigand k (1 .. 3) (bigand l (7 .. 9) (or (diff k i) (diff l j)) ((p i j n) imply (not (p k l n))))))))");
//        formulaBox11.setText("(bigand i (4 .. 6) (bigand j (7 .. 9) (bigand n (1 .. 9) (bigand k (4 .. 6) (bigand l (7 .. 9) (or (diff k i) (diff l j)) ((p i j n) imply (not (p k l n))))))))");
//        formulaBox12.setText("(bigand i (7 .. 9) (bigand j (7 .. 9) (bigand n (1 .. 9) (bigand k (7 .. 9) (bigand l (7 .. 9) (or (diff k i) (diff l j)) ((p i j n) imply (not (p k l n))))))))");
//
//        formulaBox13.setText("((((((p 1 2 3) and ((p 1 6 1) and (p 2 2 6))) and (p 2 8 5)) and (p 3 1 5)) and (p 3 7 9)) and (p 3 8 8))");
//        formulaBox14.setText("(((((((((p 4 2 8) and (p 4 6 6)) and (p 4 7 3)) and (p 4 9 2)) and (p 5 5 5)) and (p 6 1 9)) and (p 6 3 3)) and (p 6 4 8)) and (p 6 8 6))");
//        formulaBox15.setText("((((((((p 7 1 7) and (p 7 2 1)) and (p 7 3 4)) and (p 7 9 9)) and (p 8 2 2)) and (p 8 7 8)) and (p 9 4 4)) and (p 9 8 3))");









    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JMenu jMenu1;
    private javax.swing.JMenu jMenu2;
    private javax.swing.JMenuItem jMenuItem1;
    private javax.swing.JMenuItem jMenuItem10;
    private javax.swing.JMenuItem jMenuItem11;
    private javax.swing.JMenuItem jMenuItem15;
    private javax.swing.JMenuItem jMenuItem16;
    private javax.swing.JMenuItem jMenuItem2;
    private javax.swing.JMenuItem jMenuItem3;
    private javax.swing.JMenuItem jMenuItem4;
    private javax.swing.JMenuItem jMenuItem5;
    private javax.swing.JMenuItem jMenuItem6;
    private javax.swing.JMenuItem jMenuItem7;
    private javax.swing.JMenuItem jMenuItem9;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JPanel jPanel3;
    private javax.swing.JPanel jPanelFormulas;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JScrollPane jScrollPaneFormulas;
    private javax.swing.JPanel mainPanel;
    private javax.swing.JMenuBar menuBar;
    private javax.swing.JMenuItem mnuHelp;
    private javax.swing.JProgressBar progressBar;
    private javax.swing.JLabel statusAnimationLabel;
    private javax.swing.JLabel statusMessageLabel;
    private javax.swing.JPanel statusPanel;
    // End of variables declaration//GEN-END:variables

    private final Timer messageTimer;
    private final Timer busyIconTimer;
    private final Icon idleIcon;
    private final Icon[] busyIcons = new Icon[15];
    private int busyIconIndex = 0;

    private JDialog aboutBox;

    private void reset() {

        formulaBoxes.clear();
        jPanelFormulas.removeAll();

        
        for(int i = 0; i < 15; i++)
         formulaBoxes.add(new FormulaBox());

        for(FormulaBox formulaBox : formulaBoxes)
        {
            formulaBox.doLayout();
            jPanelFormulas.add(formulaBox);
        }

        jScrollPaneFormulas.revalidate();
        jPanelFormulas.doLayout();
        jScrollPaneFormulas.doLayout();
        

        formulaBoxIndiceCourant = 0;

        for(FormulaBox f : formulaBoxes)
            paletteForFormulas.addFormulaBoxToTreat(f);
    }



    private void addFormula(String formula)
    {
        if(formulaBoxIndiceCourant >= formulaBoxes.size())
        {
            FormulaBox formulaBox = new FormulaBox();
            formulaBoxes.add(formulaBox);
            jPanelFormulas.add(formulaBox);
            
        }

        formulaBoxes.get(formulaBoxIndiceCourant).setText(formula);
        formulaBoxIndiceCourant++;
    }


}