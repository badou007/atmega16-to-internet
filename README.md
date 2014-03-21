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


this don't work with VBA with my experience : vba gets the serial port of the computer 
witch is sending the message (client) , while jsp gets the serial port of the computer hosting tomcat(server) .
