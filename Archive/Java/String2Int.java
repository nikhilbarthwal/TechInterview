import java.lang.String;
import java.lang.Exception;
import java.lang.Integer;

class String2Int
{
    public static int Convert(String input) throws Exception
    {
        String str = input.trim();
        final int n = str.length();

        if (n == 0)
            throw new Exception("Empty string");

        final char ch = str.charAt(0);                // Get the first character of the string
        final boolean sign = ch != '-';               // Assume the number is positive;
        int pos = (ch == '-') || (ch == '+') ? 1 : 0; // Starting position for the string
        while (str.charAt(pos) == '0')                // Optimization: Trim all leading zeroes
            pos++;

        final int limit = sign ? Integer.MAX_VALUE : Integer.MIN_VALUE;
        int result = 0;
        int exp = sign ? 1 : -1;
        for (int i = n - 1; i >= pos; i--)
        {
            final char c = str.charAt(i);
            if ((c < '0') || (c > '9'))
                throw new Exception("Invalid format");
            int delta = exp * (c - '0');

            // Check if there is more room to add, then add else throw overflow exception
            if (sign ? ((limit - result) >= delta) : ((limit - result) <= delta))
                result += delta;
            else
                throw new Exception("Integer overflow");

            // If the limit of # of digits have reached and there are still more digits left
            // to be processed, then throw overflow exception.
            if ((((double) limit / exp) < (double) 10) && (i > pos))
                throw new Exception("Integer overflow");
            else
                exp *= 10;
        }

        return result;
    }
}
