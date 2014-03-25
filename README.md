atmega16-to-internet
====================

using java,tomcat for jsp , javacomm for rs232 communication ,atmega16 :  
to send message to atmega16 and display message on 4 sure electronic 0832 pannels throw internet

I suppose you have java installed ; if not , dowload and install java and make it working fine .

download and install tomcat in c:\tom : tomcat5.5 in my case .

copy the folder named atmega to tomcat/webbapps

dowload and install javacomm as indicated in the read me file :
in my case , things work only with winn32com.dll in <java>/bin but not in <java>/jre/bin
and javax.comm.properties in <java>/jre/lib/


compile and load atmega16 with the obtained hex file from the project ;


connect to localhost:8080/atmega , fill the JOPTion.message and click Ok to view the message scrolling on pannels .

If you have dyndns adress and can connect to your computer with the dyndns name , you will be able to send message 
from every where !!


this don't work with VBA with my experience : vba gets the serial port of the computer <br>
witch is sending the message (client) , while jsp gets the serial port of the computer hosting tomcat(server) .<br>

****************************<br>

IMPORTANT : since we are working with tomcat you have to creat your web-application in the following :<br>
1°) create a "dossier" named atmega .<br>
2°) In this dossier atmega create a dossier namer WEB-INF : copy the two jsp files in this folder .<br>
3°) in this "dossier" WEB-INF create a "dossier" named sr and a "dossier" named classes . <br>
4°) In sr create a "dossier" named write(because of the package in SimpleWrite4 .copy SimpleWrite4.java in the "dossier" named write .<br>
5°)copy the file web.xml in folder WEB-INF .<br>
6°)Modify the com-port with your's in SimpleWrite4 .
7°) create the bat file with c.bat , execute c.bat to get SimpleWrite4.class in the folder classes .<br>

now your web application is ready , put it in the folder webapps of tomcat .<br>
******************************************************<br>
8°) create an AVR project with the remainding files , build and load on Atmega16 .<br>
9°) Connect 4 or 3 or 2 or 1 sureElectronic 0832 pannels as indicated in the defines .<br>
9 open the web browser , goto localhost:8080/atmega , write a message of length 42 caracters in the JOPtion.Input message and click OK and your message will be scrolling on the pannels .<br>
10°) if you have a dyndns address , send messages to your pannels from evry where .<br>






