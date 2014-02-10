DefaultMutableTreeNode swing = new DefaultMutableTreeNode("Swing");
DefaultMutableTreeNode containers = new DefaultMutableTreeNode("Containers");
DefaultMutableTreeNode controls = new DefaultMutableTreeNode("Controls");
DefaultMutableTreeNode menus = new DefaultMutableTreeNode("Menus");


swing.add(containers);
swing.add(controls);
swing.add(menus);

JTree jtree = new JTree(swing);
