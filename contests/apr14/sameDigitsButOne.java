private static boolean sameDigitsButOne(String s) {
	char same;
	if (s.charAt(0) == s.charAt(1) || s.charAt(0) == s.charAt(2))
		same = s.charAt(0);
	else if (s.charAt(1) == s.charAt(2))
		same = s.charAt(1);
	else
		return false;

	int not_same_count = 0;
	for (int i = 0; i < s.length(); i++)
		if (s.charAt(i) != same)
			if (not_same_count == 1)
				return false;
			else
				not_same_count++;

	return true;
}