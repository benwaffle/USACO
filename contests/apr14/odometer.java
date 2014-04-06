import java.io.*;
import java.util.StringTokenizer;

public class odometer {
	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("odometer.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("odometer.out")));
		StringTokenizer st = new StringTokenizer(f.readLine());

		long moos = 0;

		String xs = st.nextToken();
		String ys = st.nextToken();
		long x = Long.parseLong(xs);
		long y = Long.parseLong(ys);

		String cur;
		for (int len = xs.length(); len <= ys.length(); len++) { 		// each possible length
			for (int odd_dig_i = 0; odd_dig_i < len; odd_dig_i++) { 	// index of unique digit
				for (int odd_dig = 0; odd_dig <= 9; odd_dig++) { 		// the unique digit
					for (int same_dig = 0; same_dig <= 9; same_dig++) { // the common digit
						if (same_dig == odd_dig || 							// common == unique
								(odd_dig == 0 && odd_dig_i == 0) ||			// starts with 0
								(odd_dig_i != 0 && same_dig == 0))			// start with 0
							continue;

						cur = multiple(same_dig, odd_dig_i) +			// generate number
								odd_dig +
								multiple(same_dig, len - odd_dig_i - 1);
						long curl = Long.parseLong(cur);
						if (curl >= x && curl <= y)
							moos++;
					}
				}
			}
		}

		out.println(moos);
		out.close();
		f.close();
		System.exit(0);
	}

	static StringBuilder sb = new StringBuilder();

	private static String multiple(int c, int count) {
		sb.delete(0, sb.length());
		for (int i = 0; i < count; i++)
			sb.append(c);
		return sb.toString();
	}
}
