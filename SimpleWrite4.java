package write;
import java.io.*;
import java.util.*;
import javax.comm.*;



public class SimpleWrite4{
    
    CommPortIdentifier portId;
   
public String messageString;
   SerialPort serialPort;
   OutputStream outputStream;
   

public byte[] mes;

    public SimpleWrite4(String port,String x) {
messageString=x; 
mes=messageString.getBytes();


         try {
				portId = CommPortIdentifier.getPortIdentifier(port);
			} catch (NoSuchPortException e) {}

                       try{ serialPort = (SerialPort)portId.open("diop", 2000);
                    		} catch (PortInUseException e) {}
                    
                    try 			{
                        serialPort.setSerialPortParams(9600,
                            SerialPort.DATABITS_8,
                            SerialPort.STOPBITS_1,
                            SerialPort.PARITY_NONE);
                    				} catch (UnsupportedCommOperationException e) {}
try 		{
                        outputStream = serialPort.getOutputStream();
			
                    			} catch (IOException e) {}
                    try 				{
			for(int i=0;i<mes.length;i++)
			
                        outputStream.write(mes[i]);
                    					} catch (IOException e) {}
serialPort.close();
try{
outputStream.close();
}catch(IOException e) {}
                			 }

public static void main(String[] args)
{
SimpleWrite4 sw4 = new SimpleWrite4("COM5","SALUT");

}

            }
        
    

