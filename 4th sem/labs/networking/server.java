package socket;

import java.net.*;  
import java.io.*;  
class MyServer{  
    public static void main(String args[])throws Exception{  
    	ServerSocket ss=new ServerSocket(6000);
    	System.out.println("Server has started!! Waiting for connection!");
    	Socket s=ss.accept();
    	System.out.println("Connected successfully!!");
    	DataInputStream din = new DataInputStream(s.getInputStream());
    	DataOutputStream dout = new DataOutputStream(s.getOutputStream());
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	String str1 = din.readUTF();
    	System.out.println("Message received from client is: " + str1);
    	System.out.println("Enter the message to be sent to client:");
    	String str2 = br.readLine();
    	br.close();
    	dout.writeUTF(str2);
    	dout.flush();
    	dout.close();
    	din.close();
    	s.close();  
    	ss.close();  
    }
}   