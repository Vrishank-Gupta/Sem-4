package socket;

import java.net.*;  
import java.io.*; 

class MyClient{  
    public static void main(String args[])throws Exception{  
    	Socket s=new Socket("localhost",6000); 
    	DataInputStream din=new DataInputStream(s.getInputStream());
    	DataOutputStream dout=new DataOutputStream(s.getOutputStream());
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	System.out.println("Enter the message to be sent to server: ");
    	String str1 = br.readLine();
    	br.close();
    	dout.writeUTF(str1);
    	dout.flush();
    	String str2 = din.readUTF();
    	System.out.println("Message received from server is: " + str2);
    	din.close();
    	dout.close();
    	s.close();  
    	
    }
}  