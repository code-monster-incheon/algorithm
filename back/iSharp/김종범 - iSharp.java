package 프로그래머스;

import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String s = sc.nextLine();
		String[] arr = s.split(" ");
		String[] res = new String[arr.length];

		for (int i = 0; i < arr.length; i++) {
			arr[i] = arr[i].replace(",", "");
			arr[i] = arr[i].replace(";", "");

			if (i == 0) {
				continue;
			}

			res[i] = arr[0];
			String name = "";
			for (int j = arr[i].length() - 1; j >= 0; j--) {
				if ((arr[i].charAt(j) >= 'A' && arr[i].charAt(j) <= 'Z')
						|| (arr[i].charAt(j) >= 'a' && arr[i].charAt(j) <= 'z')) {
					name += arr[i].charAt(j);
				} else {
					if (arr[i].charAt(j) == ']') {
						res[i] += '[';
					} else if (arr[i].charAt(j) == '[') {
						res[i] += ']';

					} else {
						res[i] += arr[i].charAt(j);

					}

				}

			}

			String new_name = "";
			for (int j = name.length() - 1; j >= 0; j--) {
				new_name += name.charAt(j);
			}
			res[i] += " " + new_name + ";";
			System.out.println(res[i]);

		}

	}

}