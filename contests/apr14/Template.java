import java.io.*;
import java.util.StringTokenizer;


public class Template {
	public static void main(String[] args) throws IOException{
		BufferedReader f = new BufferedReader(new FileReader("task.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("task.out")));
		StringTokenizer st = new StringTokenizer(f.readLine());
		
		
		out.close();
		f.close();
	    System.exit(0);
	}
}
