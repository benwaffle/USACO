import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;


public class fairphoto {
	static Cow[] cows;
	
	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("fairphoto.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("fairphoto.out")));
		StringTokenizer st = new StringTokenizer(f.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		cows = new Cow[n];
		
		for (int i = 0; i < cows.length; i++){
			st = new StringTokenizer(f.readLine());
			cows[i] = new Cow(Integer.parseInt(st.nextToken()), st.nextToken().charAt(0));
		}
		
		Arrays.sort(cows);
		
		int maxsize = 0;
		for (int width = n; width > 1; width--){
			if (maxsize != 0) break;
			int laststart = n-width;
			for (int start = 0; start <= laststart; start++){
				if (isFair(start, width+start-1)){
					maxsize = Math.max(size(start, width+start-1), maxsize);
				}
			}
		}
		
		out.println(maxsize);
		out.close();
		f.close();
	    System.exit(0);
	}
	
	static int size(int from, int to){
		return cows[to].x_i - cows[from].x_i;
	}
	
	static boolean isFair(int from, int to) {
		int sum = 0;
		for (int i = from; i <= to; i++)
			sum += cows[i].b_i;
		
		return sum == 0 || sum == (to-from+1) || ((to-from+1) % 2 == 0 && sum == (to-from+1)/2);
	}
	
	static class Cow implements Comparable<Cow> {
		final static int H = 0, G = 1;
		int x_i, b_i;
		
		public Cow(int x_i, char b_i) {
			this.x_i = x_i;
			this.b_i = (b_i == 'H' ? H : G);
		}

		@Override
		public int compareTo(Cow o) {
			return x_i - o.x_i;
		}
		
		@Override
		public String toString() {
			return x_i + ": " + (b_i == H ? 'H' : 'G');
		}
	}
}
