import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			String s = sc.next();
			if (s.length() == 1)
				cnt++;
			else if (isGroup(s))
				cnt++;
		}
		System.out.println(cnt);
	}

	static boolean isGroup(String s) {
		int size = s.length();
		int[] check = new int[26];

		check[s.charAt(0) - 97] = 1;
		boolean flag = true;
		for (int i = 1; i < size; i++) {
			if (check[s.charAt(i) - 97] != 0 && s.charAt(i - 1) != s.charAt(i)) {
				flag = false;
				break;
			}
            check[s.charAt(i) - 97] = 1;
		}
		return flag;
	}

}