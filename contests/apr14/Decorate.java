import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Decorate {
	static Pasture[] pastures;

	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("decorate.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("decorate.out")));
		StringTokenizer st = new StringTokenizer(f.readLine());

		int num_past = Integer.parseInt(st.nextToken()), paths = Integer.parseInt(st.nextToken());

		pastures = new Pasture[num_past];

		for (int i = 0; i < paths; i++) {
			st = new StringTokenizer(f.readLine());
			int a_i = Integer.parseInt(st.nextToken());
			int b_i = Integer.parseInt(st.nextToken());

			if (pastures[a_i - 1] == null)
				pastures[a_i - 1] = new Pasture(a_i);
			if (pastures[b_i - 1] == null)
				pastures[b_i - 1] = new Pasture(b_i);

			pastures[a_i - 1].add(pastures[b_i - 1]);
		}
		
		try {
			pastures[0].sign = 'J';
			decorate(pastures[0]);
		} catch (Exception e) {
			jcount = -1;
		}

		out.println(jcount == -1 ? jcount : Math.max(jcount, pastures.length - jcount));
		out.close();
		f.close();
		System.exit(0);
	}

	static int jcount = 1;

	static void decorate(Pasture p) throws Exception {
		if (p.sign == 0) {
			System.err.println(p.sign + " is not a valid sign");
			System.exit(1);
		}
		for (int i = 0; i < p.connected.size(); i++) {
			if (p.get(i).sign == 0) {
				p.get(i).sign = fj(p.sign);
				jcount += fj(p.sign) == 'J' ? 1 : 0;
				decorate(p.get(i));
			} else if (p.get(i).sign == p.sign) { throw new Exception(); } // otherwise fine
		}
	}

	static char fj(char c) {
		return c == 'J' ? 'F' : 'J';
	}

	static class Pasture {
		char sign;
		int id;
		ArrayList<Pasture> connected;

		public Pasture(int id) {
			this.id = id;
			connected = new ArrayList<Pasture>();
			sign = 0;
		}

		void add(Pasture i) {
			connected.add(i);
		}

		Pasture get(int i) {
			return connected.get(i);
		}

		@Override
		public String toString() {
			String me = id + ": ";
			for (Pasture p : connected)
				me += p.id + ", ";
			return me;
		}
	}
}
