<H1>ça y est : le message est parti.</H1><br>
<%@ page import="write.*"  %>
<%@ page import="javax.swing.JOptionPane" %>

<%! String messageString ; %>

<% messageString=JOptionPane.showInputDialog(null,"entrer un message de 42 caracteres à afficher"); %>
<%! SimpleWrite4 sw ; %>

<% out.println("<br>le message à afficher est : " + messageString);%>
<% sw=new SimpleWrite4("COM5",messageString);  %>

<!-- change COM5 with your port -->
