import java.lang.String;
import java.lang.Exception;

class String2Int_Test
{
    private static void test(String str)
    {
        System.out.print("\"" + str + "\"\t-->\t");
        try
        {
            System.out.println(String2Int.Convert(str));
        }
        catch(Exception e)
        {
            System.out.println("Exception: " + e.getMessage());
        }
    }

    public static void main(String[] args)
    {
        test("+000002147483647");
        test("-0000002147483648");
        test("    02147483648  ");
        test(" adfasfdgher ewr");
        return;
    }
}
