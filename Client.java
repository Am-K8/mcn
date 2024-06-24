import java.net.*;
import java.io.*;
public class Client {
    public static void main(String[] args) {
        String serverAddress = "192.168.56.1"; // Server's IP address
        int serverPort = 12345; // Server's port number
 
        try {
            // Create a socket connecting to the server
            Socket socket = new Socket(serverAddress, serverPort);
 
            // Get the output stream of the socket
            OutputStream outputStream = socket.getOutputStream();
 
            // Create a PrintWriter to write messages to the output stream
            PrintWriter out = new PrintWriter(outputStream, true);
 
            // Send a message to the server
            out.println("Hello, server, Dawan reporting in!");
 
            // Close the socket
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}