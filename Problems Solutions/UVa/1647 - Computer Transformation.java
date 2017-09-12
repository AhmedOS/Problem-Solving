import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{

	public static void main(String args[])
	{
		Scanner in = new Scanner(System.in);
		while (in.hasNextInt()) {
			int n = in.nextInt();
			n--;
			BigInteger ans = new BigInteger("0");
			boolean sign = false;
			while (n > 0) {
				n--;
				ans = ans.add(ans);
				if (sign)
					ans = ans.add(BigInteger.valueOf(-1));
				else
					ans = ans.add(BigInteger.valueOf(1));
				sign = !sign;
			}
			System.out.println(ans);
		}
	}

}
