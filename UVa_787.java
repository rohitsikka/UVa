import java.math.BigInteger;
import java.util.Scanner;
public class UVa_787
{
    public static void main(String[] args )
    {
        Scanner sc=new Scanner(System.in);
        int[] arr=new int[110];
        int n;
        n=0;
        while(sc.hasNext())
        {
            int cur=sc.nextInt();
            if(cur==-999999)
            {
                BigInteger maxProd=BigInteger.valueOf(cur);
                BigInteger curProd=BigInteger.valueOf(1);
                for(int i=0;i<n;i++)
                {
                    curProd=BigInteger.valueOf(1);
                    for(int j=i;j<n;j++)
                    {
                        curProd=curProd.multiply(BigInteger.valueOf(arr[j]));
                        if(curProd.compareTo(maxProd)==1)
                            maxProd=curProd;
                    }
                }
                System.out.println(maxProd.toString());
                n=0;
                continue;
            }
            arr[n]=cur;
            n++;
        }
    }
}
