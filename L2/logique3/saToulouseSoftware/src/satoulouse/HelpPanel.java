/*
 * HelpPanel.java
 *
 * Created on 27 août 2008, 12:24
 */

package satoulouse;

import java.io.IOException;
import java.util.Stack;
import javax.swing.event.HyperlinkEvent.EventType;

/**
 *
 * @author  proprietaire
 */
public class HelpPanel extends javax.swing.JPanel {

    Stack<java.net.URL> lastPages = new Stack<java.net.URL>();


    /** Creates new form HelpPanel */
    public HelpPanel() {
        initComponents();
    }
    
    
    private void page_last()
    {
        if((lastPages.size() > 1))
        {
            lastPages.pop();
            page_show(lastPages.pop());
        }


    }



    
    void page_show(java.net.URL helpURL)
    {
         if (helpURL != null) {
            try {
                jEditorPane.setPage(helpURL);
            } catch (IOException e) {
                System.err.println("Attempted to read a bad URL: " + helpURL);
            }
        } else {
            System.err.println("Couldn't find file: " + helpURL.getFile());
        }
        lastPages.push(helpURL);
    }
    
    
    
    void page_show(String name)
    {
        java.net.URL helpURL = getClass().getResource("resources/help/" + 
                                name);
        
        page_show(helpURL);
    }



    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jScrollPane1 = new javax.swing.JScrollPane();
        jEditorPane = new javax.swing.JEditorPane();
        jToolBar1 = new javax.swing.JToolBar();
        cmdHelp = new javax.swing.JButton();

        setName("Form"); // NOI18N
        setLayout(new java.awt.BorderLayout());

        jScrollPane1.setBorder(null);
        jScrollPane1.setName("jScrollPane1"); // NOI18N

        org.jdesktop.application.ResourceMap resourceMap = org.jdesktop.application.Application.getInstance(satoulouse.SatoulouseApp.class).getContext().getResourceMap(HelpPanel.class);
        jEditorPane.setBackground(resourceMap.getColor("jEditorPane.background")); // NOI18N
        jEditorPane.setBorder(null);
        jEditorPane.setEditable(false);
        jEditorPane.setName("jEditorPane"); // NOI18N
        jEditorPane.addHyperlinkListener(new javax.swing.event.HyperlinkListener() {
            public void hyperlinkUpdate(javax.swing.event.HyperlinkEvent evt) {
                jEditorPaneHyperlinkUpdate(evt);
            }
        });
        jScrollPane1.setViewportView(jEditorPane);

        add(jScrollPane1, java.awt.BorderLayout.CENTER);

        jToolBar1.setFloatable(false);
        jToolBar1.setRollover(true);
        jToolBar1.setName("jToolBar1"); // NOI18N

        cmdHelp.setIcon(resourceMap.getIcon("cmdHelp.icon")); // NOI18N
        cmdHelp.setText(resourceMap.getString("cmdHelp.text")); // NOI18N
        cmdHelp.setFocusable(false);
        cmdHelp.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        cmdHelp.setName("cmdHelp"); // NOI18N
        cmdHelp.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        cmdHelp.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cmdHelpActionPerformed(evt);
            }
        });
        jToolBar1.add(cmdHelp);

        add(jToolBar1, java.awt.BorderLayout.PAGE_START);
    }// </editor-fold>//GEN-END:initComponents

private void jEditorPaneHyperlinkUpdate(javax.swing.event.HyperlinkEvent evt) {//GEN-FIRST:event_jEditorPaneHyperlinkUpdate
// TODO add your handling code here:
    if(evt.getEventType() == EventType.ACTIVATED)
    {
        if(evt.getURL().getFile().endsWith(".txt"))
        {
            
           // if(fenetreEvaluation != null)
//                 try {
//                    //fenetreEvaluation.writeExpression(TextFile.lire_dans_une_url(evt.getURL()));
//                } catch (FileNotFoundException ex) {
//                    Logger.getLogger(HelpPanel.class.getName()).log(Level.SEVERE, null, ex);
//                } catch (IOException ex) {
//                    Logger.getLogger(HelpPanel.class.getName()).log(Level.SEVERE, null, ex);
//                }
        }
        else
         page_show(evt.getURL());
    }
}//GEN-LAST:event_jEditorPaneHyperlinkUpdate

private void cmdHelpActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cmdHelpActionPerformed
    page_last();
}//GEN-LAST:event_cmdHelpActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton cmdHelp;
    private javax.swing.JEditorPane jEditorPane;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JToolBar jToolBar1;
    // End of variables declaration//GEN-END:variables

}
